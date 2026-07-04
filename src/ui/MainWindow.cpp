#include "MainWindow.h"

#include <QLabel>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupTheme();
    setupUI();
    showFullScreen();
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
    auto *label = new QLabel("BlockTorch", this);
    label->setAlignment(Qt::AlignCenter);

    QFont font = label->font();
    font.setPointSize(48);
    font.setBold(true);
    label->setFont(font);

    setCentralWidget(label);
    setWindowTitle("BlockTorch");
}
