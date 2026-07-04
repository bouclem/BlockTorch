#pragma once

#include <QWidget>
#include <QString>

class Block : public QWidget {
    Q_OBJECT

public:
    explicit Block(const QString &label, const QColor &color, QWidget *parent = nullptr);

    QString label() const { return m_label; }

signals:
    void doubleClicked();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    QString m_label;
};
