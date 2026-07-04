#include "WorkspaceSavesView.h"

#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

WorkspaceSavesView::WorkspaceSavesView(QWidget *parent)
    : QWidget(parent)
{
    auto *title = new QLabel("Workspace Saves", this);
    title->setAlignment(Qt::AlignCenter);
    QFont titleFont = title->font();
    titleFont.setPointSize(28);
    titleFont.setBold(true);
    title->setFont(titleFont);

    auto *savesList = new QListWidget(this);
    savesList->setMinimumHeight(300);
    auto *emptyItem = new QListWidgetItem("No saves found", savesList);
    emptyItem->setFlags(emptyItem->flags() & ~Qt::ItemIsSelectable);

    auto *continueBtn = new QPushButton("Continue", this);
    continueBtn->setFixedSize(150, 40);

    auto *backBtn = new QPushButton("Back", this);
    backBtn->setFixedSize(100, 35);

    auto *layout = new QVBoxLayout(this);
    layout->addStretch();
    layout->addWidget(title);
    layout->addSpacing(20);
    layout->addWidget(savesList);
    layout->addSpacing(20);

    auto *btnRow = new QHBoxLayout();
    btnRow->addWidget(backBtn);
    btnRow->addStretch();
    btnRow->addWidget(continueBtn);
    layout->addLayout(btnRow);
    layout->addStretch();

    connect(continueBtn, &QPushButton::clicked, this, &WorkspaceSavesView::continueRequested);
    connect(backBtn, &QPushButton::clicked, this, &WorkspaceSavesView::backRequested);
}
