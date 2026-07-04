#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class WorkspaceView : public QWidget {
    Q_OBJECT

public:
    explicit WorkspaceView(QWidget *parent = nullptr);

private:
    QWidget *m_leftSidebar;
    QWidget *m_canvas;
    QWidget *m_rightSidebar;
    QVBoxLayout *m_canvasLayout;
    QLabel *m_paramsLabel;

    void setupLeftSidebar();
    void setupCanvas();
    void setupRightSidebar();
    void addBlockToCanvas(const QString &name, const QColor &color);
    void updateParams();
};
