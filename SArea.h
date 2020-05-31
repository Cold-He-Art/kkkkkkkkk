#ifndef SAREA_H
#define SAREA_H
#include <QWidget>


class SArea: public QWidget
{
    Q_OBJECT
public:
    SArea(QWidget *parent = 0);
    bool openimage(const QString &fileName);
    bool saveimage(const QString &fileName, const char *fileFormat);
    //bool isModified() {const return modified;}
private:
        void resizeImage(QImage *image, const QSize &newSize);
        bool modified;
        QImage image;

};
#endif // SAREA_H
