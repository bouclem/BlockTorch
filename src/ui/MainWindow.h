#pragma once

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private:
    void setupTheme();
    void setupUI();

    QStackedWidget *m_stacked;
    int m_homeIndex;
    int m_savesIndex;
    int m_workspaceIndex;
};
