#include "WorkspaceView.h"

#include <QLabel>
#include <QHBoxLayout>

WorkspaceView::WorkspaceView(QWidget *parent)
    : QWidget(parent)
{
    m_leftSidebar = new QWidget(this);
    m_leftSidebar->setFixedWidth(220);
    m_leftSidebar->setStyleSheet("background-color: #2a2a2a; border-right: 1px solid #3a3a3a;");

    auto *leftLabel = new QLabel("Blocks", m_leftSidebar);
    leftLabel->setAlignment(Qt::AlignCenter);
    leftLabel->setStyleSheet("color: #888888; padding: 10px;");
    auto *leftLayout = new QVBoxLayout(m_leftSidebar);
    leftLayout->addWidget(leftLabel);
    leftLayout->addStretch();

    m_canvas = new QWidget(this);
    m_canvas->setStyleSheet("background-color: #1e1e1e;");

    auto *canvasLabel = new QLabel("Canvas", m_canvas);
    canvasLabel->setAlignment(Qt::AlignCenter);
    canvasLabel->setStyleSheet("color: #555555; font-size: 18px;");
    auto *canvasLayout = new QVBoxLayout(m_canvas);
    canvasLayout->addWidget(canvasLabel);
    canvasLayout->addStretch();

    m_rightSidebar = new QWidget(this);
    m_rightSidebar->setFixedWidth(260);
    m_rightSidebar->setStyleSheet("background-color: #2a2a2a; border-left: 1px solid #3a3a3a;");

    auto *rightLabel = new QLabel("Properties", m_rightSidebar);
    rightLabel->setAlignment(Qt::AlignCenter);
    rightLabel->setStyleSheet("color: #888888; padding: 10px;");
    auto *rightLayout = new QVBoxLayout(m_rightSidebar);
    rightLayout->addWidget(rightLabel);
    rightLayout->addStretch();

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_leftSidebar);
    layout->addWidget(m_canvas, 1);
    layout->addWidget(m_rightSidebar);
}
