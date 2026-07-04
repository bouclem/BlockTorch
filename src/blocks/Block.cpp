#include "Block.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>

Block::Block(const QString &label, const QColor &color, QWidget *parent)
    : QWidget(parent)
    , m_label(label)
{
    setFixedSize(140, 50);
    setStyleSheet(QString("background-color: %1; border-radius: 8px; border: 2px solid #555555;").arg(color.name()));

    auto *lbl = new QLabel(label, this);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setStyleSheet("color: white; font-size: 14px; font-weight: bold; border: none;");

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(4, 4, 4, 4);
    layout->addWidget(lbl);
}

void Block::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit doubleClicked();
    }
    QWidget::mouseDoubleClickEvent(event);
}
