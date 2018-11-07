#ifndef CANVAS_H
#define CANVAS_H
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "global.h"

using namespace GLOBAL;

class Canvas  : public QGraphicsScene
{
    Q_OBJECT

    public:
        Canvas(QImage& image, QObject *parent = 0);

        /* Mouse events*/
        virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
        virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

        /**
         * @brief setImage - Displays passed image in the scene
         * @param image - QImage that needs to be displayed in the scene
         * @return - Pointer to QImage being displayed
         */
        void setImage(QImage& image);

        /**
         * @brief initializeEmptyImage - sets image alpha to 0
         * @param image - image to be initialized
         */
        void initializeEmptyImage(QImage& image);

    signals:
        void mousePressed(QPointF point);
        void mouseMoved(QPointF point);
        void mouseReleased(QPointF point);

    public slots:

    private:
        QPixmap pixmap;
        QImage& image;
        // Converts and returns (non-scaled) grid coords
        QPointF convertToPoint(QPointF scaledPos);
        // Updates pixmap based on image by scaling it appropriately
        void updatePixmap();
};

#endif // CANVAS_H
