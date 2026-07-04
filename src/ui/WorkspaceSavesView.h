#pragma once

#include <QWidget>

class WorkspaceSavesView : public QWidget {
    Q_OBJECT

public:
    explicit WorkspaceSavesView(QWidget *parent = nullptr);

signals:
    void continueRequested();
    void backRequested();
};
