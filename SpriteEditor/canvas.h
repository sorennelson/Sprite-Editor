#ifndef CANVAS_H
#define CANVAS_H
#include <QPixmap>
#include <QGraphicsScene>

class Canvas  : public QGraphicsScene
{
    Q_OBJECT

    public:
        Canvas(QObject *parent = 0);
        virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
        void setPixel(int x, int y, QRgb rgb);


    private:
        QPixmap pixmap;
        QImage image;
        int sizeX;
        int sizeY;
};

#endif // CANVAS_H
