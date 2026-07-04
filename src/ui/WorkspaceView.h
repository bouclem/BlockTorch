#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpinBox>

class WorkspaceView : public QWidget {
    Q_OBJECT

public:
    explicit WorkspaceView(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QWidget *m_leftSidebar;
    QWidget *m_canvas;
    QWidget *m_rightSidebar;
    QVBoxLayout *m_canvasLayout;
    QLabel *m_paramsLabel;

    QSpinBox *m_layersSpin;
    QSpinBox *m_hiddenSpin;
    QSpinBox *m_vocabSpin;
    QSpinBox *m_seqSpin;
    QSpinBox *m_batchSpin;

    QPoint m_dragStartPos;

    void setupLeftSidebar();
    void setupCanvas();
    void setupRightSidebar();
    void addBlockToCanvas(const QString &name, const QColor &color);
    void updateParams();
};
