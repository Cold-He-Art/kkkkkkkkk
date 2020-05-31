#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QInputDialog>
#include <QColorDialog>
#include <QDebug>

#define DEFAULT_SIZE 5

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mImage = new QImage(QApplication::desktop()->size(), QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(mImage);
    mEnabled = false;
    mColor = QColor(Qt::black);
    msize = DEFAULT_SIZE;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mPainter;
    delete mImage;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(mImage->rect(), Qt::white);
    painter.drawImage(0, 0, *mImage);
    e->accept();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    mEnabled = true;
    mBegin=e->pos();
    e->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (!mEnabled)
    {
        e->accept();
        return;
    }

    QPen pen(mColor);
   // pen.SetCapStyle(Qt::RoundCap);
    pen.setWidth(msize);
    mEnd = e->pos();
    mPainter->setPen(pen);
    mPainter->drawLine(mBegin, mEnd);
    mBegin = mEnd;
    update();
    e->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    mEnabled = false;
    e->accept();
}

void MainWindow::on_actionWidth_triggered()
{
    msize = QInputDialog::getInt(this , "Width of pen", "Enter width" , 5, 1);
}

void MainWindow::on_actionColor_triggered()
{
    mColor = QColorDialog::getColor(Qt::black, this, "Enter color");
}

void MainWindow::on_actionEraser_triggered()
{
     mColor = QColor(Qt::white);
}

void MainWindow::on_actionBrush_triggered()
{
    mColor = QColor(Qt::black);
}

void MainWindow::on_actionDelete_triggered()
{
    close();
}

void MainWindow::on_actionClear_triggered()
{

}
