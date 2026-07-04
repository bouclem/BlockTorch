#include "WorkspaceView.h"
#include "blocks/StartBlock.h"
#include "blocks/StopBlock.h"
#include "core/Params.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QApplication>

WorkspaceView::WorkspaceView(QWidget *parent)
    : QWidget(parent)
    , m_leftSidebar(nullptr)
    , m_canvas(nullptr)
    , m_rightSidebar(nullptr)
    , m_canvasLayout(nullptr)
    , m_paramsLabel(nullptr)
    , m_layersSpin(nullptr)
    , m_hiddenSpin(nullptr)
    , m_vocabSpin(nullptr)
    , m_seqSpin(nullptr)
    , m_batchSpin(nullptr)
{
    m_leftSidebar = new QWidget(this);
    m_leftSidebar->setFixedWidth(220);
    m_leftSidebar->setStyleSheet("background-color: #2a2a2a; border-right: 1px solid #3a3a3a;");

    m_canvas = new QWidget(this);
    m_canvas->setStyleSheet("background-color: #1e1e1e;");
    m_canvas->setAcceptDrops(true);

    m_rightSidebar = new QWidget(this);
    m_rightSidebar->setFixedWidth(280);
    m_rightSidebar->setStyleSheet("background-color: #2a2a2a; border-left: 1px solid #3a3a3a;");

    setupLeftSidebar();
    setupCanvas();
    setupRightSidebar();

    m_canvas->installEventFilter(this);

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
    leftLabel->setStyleSheet("color: #aaaaaa; padding: 12px; font-size: 16px; font-weight: bold; border-bottom: 1px solid #3a3a3a;");

    auto *hintLabel = new QLabel("Drag to canvas", m_leftSidebar);
    hintLabel->setAlignment(Qt::AlignCenter);
    hintLabel->setStyleSheet("color: #666666; font-size: 11px; padding: 4px;");

    auto *startBtn = new QPushButton("Start", m_leftSidebar);
    startBtn->setStyleSheet("background-color: #2d7a2d; color: white; border-radius: 6px; padding: 10px; font-weight: bold; font-size: 13px;");

    auto *stopBtn = new QPushButton("Stop", m_leftSidebar);
    stopBtn->setStyleSheet("background-color: #7a2d2d; color: white; border-radius: 6px; padding: 10px; font-weight: bold; font-size: 13px;");

    auto *leftLayout = new QVBoxLayout(m_leftSidebar);
    leftLayout->setContentsMargins(10, 0, 10, 0);
    leftLayout->addWidget(leftLabel);
    leftLayout->addWidget(hintLabel);
    leftLayout->addSpacing(6);
    leftLayout->addWidget(startBtn);
    leftLayout->addWidget(stopBtn);
    leftLayout->addStretch();

    startBtn->installEventFilter(this);
    stopBtn->installEventFilter(this);

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

    auto *canvasLabel = new QLabel("Canvas — drag blocks here, double-click Start to run", m_canvas);
    canvasLabel->setAlignment(Qt::AlignCenter);
    canvasLabel->setStyleSheet("color: #555555; font-size: 13px; padding: 20px;");
    m_canvasLayout->addWidget(canvasLabel);
    m_canvasLayout->addStretch();
}

void WorkspaceView::setupRightSidebar()
{
    auto *rightLabel = new QLabel("Params (estimated)", m_rightSidebar);
    rightLabel->setAlignment(Qt::AlignCenter);
    rightLabel->setStyleSheet("color: #aaaaaa; padding: 12px; font-size: 16px; font-weight: bold; border-bottom: 1px solid #3a3a3a;");

    auto *formWidget = new QWidget(m_rightSidebar);
    auto *form = new QFormLayout(formWidget);
    form->setContentsMargins(10, 10, 10, 10);
    form->setSpacing(8);

    QString spinStyle = "QSpinBox { background-color: #1e1e1e; color: #dddddd; border: 1px solid #3a3a3a; border-radius: 4px; padding: 4px; } QSpinBox::up-button { width: 16px; } QSpinBox::down-button { width: 16px; }";

    m_layersSpin = new QSpinBox(formWidget);
    m_layersSpin->setRange(1, 100);
    m_layersSpin->setValue(6);
    m_layersSpin->setStyleSheet(spinStyle);

    m_hiddenSpin = new QSpinBox(formWidget);
    m_hiddenSpin->setRange(64, 8192);
    m_hiddenSpin->setSingleStep(64);
    m_hiddenSpin->setValue(512);
    m_hiddenSpin->setStyleSheet(spinStyle);

    m_vocabSpin = new QSpinBox(formWidget);
    m_vocabSpin->setRange(100, 1000000);
    m_vocabSpin->setSingleStep(1000);
    m_vocabSpin->setValue(50000);
    m_vocabSpin->setStyleSheet(spinStyle);

    m_seqSpin = new QSpinBox(formWidget);
    m_seqSpin->setRange(32, 8192);
    m_seqSpin->setSingleStep(32);
    m_seqSpin->setValue(512);
    m_seqSpin->setStyleSheet(spinStyle);

    m_batchSpin = new QSpinBox(formWidget);
    m_batchSpin->setRange(1, 512);
    m_batchSpin->setValue(32);
    m_batchSpin->setStyleSheet(spinStyle);

    QString labelStyle = "color: #aaaaaa; font-size: 12px;";

    auto addRow = [&](const QString &name, QSpinBox *spin) {
        auto *lbl = new QLabel(name, formWidget);
        lbl->setStyleSheet(labelStyle);
        form->addRow(lbl, spin);
    };

    addRow("Layers", m_layersSpin);
    addRow("Hidden", m_hiddenSpin);
    addRow("Vocab", m_vocabSpin);
    addRow("Seq Len", m_seqSpin);
    addRow("Batch", m_batchSpin);

    m_paramsLabel = new QLabel("Not run yet", m_rightSidebar);
    m_paramsLabel->setAlignment(Qt::AlignCenter);
    m_paramsLabel->setStyleSheet("color: #aaaaaa; font-size: 16px; padding: 20px;");
    m_paramsLabel->setWordWrap(true);

    auto *rightLayout = new QVBoxLayout(m_rightSidebar);
    rightLayout->setContentsMargins(0, 0, 0, 0);
    rightLayout->addWidget(rightLabel);
    rightLayout->addWidget(formWidget);
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
    config.layers = m_layersSpin->value();
    config.hiddenSize = m_hiddenSpin->value();
    config.vocabSize = m_vocabSpin->value();
    config.seqLength = m_seqSpin->value();
    config.batchSize = m_batchSpin->value();

    long long count = Params::estimate(config);
    std::string formatted = Params::format(count);

    m_paramsLabel->setText(QString("Estimated: %1\n(%2 params)")
        .arg(QString::fromStdString(formatted))
        .arg(QString::number(count)));
    m_paramsLabel->setStyleSheet("color: #66cc66; font-size: 16px; padding: 20px; font-weight: bold;");
}

bool WorkspaceView::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        auto *me = static_cast<QMouseEvent*>(event);
        if (me->button() == Qt::LeftButton) {
            m_dragStartPos = me->pos();
        }
    } else if (event->type() == QEvent::MouseMove) {
        auto *me = static_cast<QMouseEvent*>(event);
        if (!(me->buttons() & Qt::LeftButton))
            return false;
        if ((me->pos() - m_dragStartPos).manhattanLength() < QApplication::startDragDistance())
            return false;

        auto *btn = qobject_cast<QPushButton*>(watched);
        if (!btn)
            return false;

        QDrag *drag = new QDrag(btn);
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(btn->text());
        drag->setMimeData(mimeData);
        drag->exec(Qt::CopyAction);
        return true;
    }

    if (watched == m_canvas) {
        if (event->type() == QEvent::DragEnter) {
            auto *de = static_cast<QDragEnterEvent*>(event);
            if (de->mimeData()->hasText()) {
                de->acceptProposedAction();
                return true;
            }
        } else if (event->type() == QEvent::Drop) {
            auto *de = static_cast<QDropEvent*>(event);
            QString name = de->mimeData()->text();
            if (name == "Start" || name == "Stop") {
                addBlockToCanvas(name, name == "Start" ? QColor("#2d7a2d") : QColor("#7a2d2d"));
                de->acceptProposedAction();
                return true;
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}
