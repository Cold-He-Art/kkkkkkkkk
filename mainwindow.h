#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QMessageBox>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QFile>


namespace Ui {
class MainWindow;
}

class QPainter;
class QImage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *e)override;
    void mousePressEvent(QMouseEvent*e) override;
    void mouseMoveEvent(QMouseEvent*e) override;
    void mouseReleaseEvent(QMouseEvent*e) override;

private slots:
    void on_actionWidth_triggered();

    void on_actionColor_triggered();

    void on_actionEraser_triggered();

    void on_actionBrush_triggered();

    void on_actionDelete_triggered();

    void on_actionClear_triggered();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    QString currentFile = "";
    QPainter *mPainter;
    QImage *mImage;
    QPoint mBegin;
    void resize(QResizeEvent * event);
    QPoint mEnd;
    bool mEnabled; //активация
    QColor mColor;
    QWidget *m_pMyWidget;
    int msize;
};
#endif // MAINWINDOW_H
