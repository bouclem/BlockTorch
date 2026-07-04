#pragma once

#include <QWidget>

class WorkspaceView : public QWidget {
    Q_OBJECT

public:
    explicit WorkspaceView(QWidget *parent = nullptr);

private:
    QWidget *m_leftSidebar;
    QWidget *m_canvas;
    QWidget *m_rightSidebar;
};
