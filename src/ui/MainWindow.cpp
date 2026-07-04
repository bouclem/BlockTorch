#include "MainWindow.h"
#include "HomeView.h"
#include "WorkspaceSavesView.h"
#include "WorkspaceView.h"

#include <QApplication>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_stacked(nullptr)
    , m_homeIndex(0)
    , m_savesIndex(0)
    , m_workspaceIndex(0)
{
    setupTheme();
    setupUI();
    resize(1280, 720);
    setMinimumSize(800, 600);
}

void MainWindow::setupTheme()
{
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(30, 30, 30));
    darkPalette.setColor(QPalette::WindowText, QColor(225, 225, 225));
    darkPalette.setColor(QPalette::Base, QColor(42, 42, 42));
    darkPalette.setColor(QPalette::AlternateBase, QColor(30, 30, 30));
    darkPalette.setColor(QPalette::Text, QColor(225, 225, 225));
    darkPalette.setColor(QPalette::Button, QColor(45, 45, 45));
    darkPalette.setColor(QPalette::ButtonText, QColor(225, 225, 225));
    darkPalette.setColor(QPalette::ToolTipBase, QColor(42, 42, 42));
    darkPalette.setColor(QPalette::ToolTipText, QColor(225, 225, 225));

    QApplication::setPalette(darkPalette);
}

void MainWindow::setupUI()
{
    m_stacked = new QStackedWidget(this);

    auto *homeView = new HomeView(this);
    auto *savesView = new WorkspaceSavesView(this);
    auto *workspaceView = new WorkspaceView(this);

    m_homeIndex = m_stacked->addWidget(homeView);
    m_savesIndex = m_stacked->addWidget(savesView);
    m_workspaceIndex = m_stacked->addWidget(workspaceView);

    m_stacked->setCurrentIndex(m_homeIndex);

    setCentralWidget(m_stacked);
    setWindowTitle("BlockTorch");

    connect(homeView, &HomeView::workspaceRequested, [this]() {
        m_stacked->setCurrentIndex(m_savesIndex);
    });

    connect(savesView, &WorkspaceSavesView::continueRequested, [this]() {
        m_stacked->setCurrentIndex(m_workspaceIndex);
    });

    connect(savesView, &WorkspaceSavesView::backRequested, [this]() {
        m_stacked->setCurrentIndex(m_homeIndex);
    });
}
