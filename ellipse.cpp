#include "ellipse.h"

ellipse::ellipse(QWidget *parent) :
    QWidget(parent)
{
    FlagDraw = false;
}
// Вывод окружности
void ellipse::paintEvent(QPaintEvent *)
{
    if (FlagDraw == true)
    {
        QPainter Ellipse(this);
        Ellipse.setBrush(QBrush(Qt::black));
        Ellipse.drawEllipse(0, 0, 600, 600);
    }
}
