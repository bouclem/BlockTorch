#include "WorkspaceView.h"
#include "blocks/StartBlock.h"
#include "blocks/StopBlock.h"
#include "core/Params.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

WorkspaceView::WorkspaceView(QWidget *parent)
    : QWidget(parent)
    , m_leftSidebar(nullptr)
    , m_canvas(nullptr)
    , m_rightSidebar(nullptr)
    , m_canvasLayout(nullptr)
    , m_paramsLabel(nullptr)
{
    m_leftSidebar = new QWidget(this);
    m_leftSidebar->setFixedWidth(220);
    m_leftSidebar->setStyleSheet("background-color: #2a2a2a; border-right: 1px solid #3a3a3a;");

    m_canvas = new QWidget(this);
    m_canvas->setStyleSheet("background-color: #1e1e1e;");

    m_rightSidebar = new QWidget(this);
    m_rightSidebar->setFixedWidth(260);
    m_rightSidebar->setStyleSheet("background-color: #2a2a2a; border-left: 1px solid #3a3a3a;");

    setupLeftSidebar();
    setupCanvas();
    setupRightSidebar();

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_leftSidebar);
    layout->addWidget(m_canvas, 1);
    layout->addWidget(m_rightSidebar);
}

void WorkspaceView::setupLeftSidebar()
{
    auto *leftLabel = new QLabel("Blocks", m_leftSidebar);
    leftLabel->setAlignment(Qt::AlignCenter);
    leftLabel->setStyleSheet("color: #888888; padding: 10px; font-size: 16px; font-weight: bold;");

    auto *startBtn = new QPushButton("Start", m_leftSidebar);
    startBtn->setStyleSheet("background-color: #2d7a2d; color: white; border-radius: 6px; padding: 8px; font-weight: bold;");

    auto *stopBtn = new QPushButton("Stop", m_leftSidebar);
    stopBtn->setStyleSheet("background-color: #7a2d2d; color: white; border-radius: 6px; padding: 8px; font-weight: bold;");

    auto *leftLayout = new QVBoxLayout(m_leftSidebar);
    leftLayout->addWidget(leftLabel);
    leftLayout->addSpacing(10);
    leftLayout->addWidget(startBtn);
    leftLayout->addWidget(stopBtn);
    leftLayout->addStretch();

    connect(startBtn, &QPushButton::clicked, [this]() {
        addBlockToCanvas("Start", QColor("#2d7a2d"));
    });
    connect(stopBtn, &QPushButton::clicked, [this]() {
        addBlockToCanvas("Stop", QColor("#7a2d2d"));
    });
}

void WorkspaceView::setupCanvas()
{
    m_canvasLayout = new QVBoxLayout(m_canvas);
    m_canvasLayout->setContentsMargins(20, 20, 20, 20);
    m_canvasLayout->setAlignment(Qt::AlignTop);

    auto *canvasLabel = new QLabel("Canvas — double-click Start to run", m_canvas);
    canvasLabel->setAlignment(Qt::AlignCenter);
    canvasLabel->setStyleSheet("color: #555555; font-size: 14px;");
    m_canvasLayout->addWidget(canvasLabel);
    m_canvasLayout->addStretch();
}

void WorkspaceView::setupRightSidebar()
{
    auto *rightLabel = new QLabel("Params (estimated)", m_rightSidebar);
    rightLabel->setAlignment(Qt::AlignCenter);
    rightLabel->setStyleSheet("color: #888888; padding: 10px; font-size: 16px; font-weight: bold;");

    m_paramsLabel = new QLabel("Not run yet", m_rightSidebar);
    m_paramsLabel->setAlignment(Qt::AlignCenter);
    m_paramsLabel->setStyleSheet("color: #aaaaaa; font-size: 18px; padding: 20px;");
    m_paramsLabel->setWordWrap(true);

    auto *rightLayout = new QVBoxLayout(m_rightSidebar);
    rightLayout->addWidget(rightLabel);
    rightLayout->addSpacing(10);
    rightLayout->addWidget(m_paramsLabel);
    rightLayout->addStretch();
}

void WorkspaceView::addBlockToCanvas(const QString &name, const QColor &color)
{
    Block *block = nullptr;
    if (name == "Start") {
        block = new StartBlock(m_canvas);
    } else if (name == "Stop") {
        block = new StopBlock(m_canvas);
    } else {
        block = new Block(name, color, m_canvas);
    }

    int insertPos = m_canvasLayout->count() - 1;
    m_canvasLayout->insertWidget(insertPos, block, 0, Qt::AlignLeft);

    if (name == "Start") {
        connect(block, &Block::doubleClicked, this, &WorkspaceView::updateParams);
    }
}

void WorkspaceView::updateParams()
{
    ParamConfig config;
    long long count = Params::estimate(config);
    std::string formatted = Params::format(count);

    m_paramsLabel->setText(QString("Estimated: %1\n(%2 params)")
        .arg(QString::fromStdString(formatted))
        .arg(QString::number(count)));
    m_paramsLabel->setStyleSheet("color: #66cc66; font-size: 18px; padding: 20px; font-weight: bold;");
}
