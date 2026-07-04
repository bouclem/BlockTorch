#include "HomeView.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

HomeView::HomeView(QWidget *parent)
    : QWidget(parent)
{
    auto *title = new QLabel("BlockTorch", this);
    title->setAlignment(Qt::AlignCenter);
    QFont titleFont = title->font();
    titleFont.setPointSize(48);
    titleFont.setBold(true);
    title->setFont(titleFont);

    auto *version = new QLabel("v0.0.6", this);
    version->setAlignment(Qt::AlignCenter);
    QFont versionFont = version->font();
    versionFont.setPointSize(14);
    version->setFont(versionFont);
    version->setStyleSheet("color: #888888;");

    auto *workspaceBtn = new QPushButton("Workspace", this);
    workspaceBtn->setFixedSize(200, 50);
    QFont btnFont = workspaceBtn->font();
    btnFont.setPointSize(14);
    workspaceBtn->setFont(btnFont);

    auto *layout = new QVBoxLayout(this);
    layout->addStretch();
    layout->addWidget(title);
    layout->addWidget(version);
    layout->addSpacing(40);
    layout->addWidget(workspaceBtn, 0, Qt::AlignCenter);
    layout->addStretch();

    connect(workspaceBtn, &QPushButton::clicked, this, &HomeView::workspaceRequested);
}
