#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <vector>
#include "global.h"


class Tools : public QObject
{
    Q_OBJECT

public:
    Tools(QImage* image, QImage* previewImage);
    ~Tools();
    void setImage(QImage* image);

    void setSelectedTool(Global::Tool tool);
    void setLeftSelectedColor(QColor color);
    void setRightSelectedColor(QColor color);

    void setBrushSize(int size);

public slots:
    void handleMousePress(int button, QPointF point);
    void handleMouseMove(int button, QPointF point);
    void handleMouseRelease(int button, QPointF point);

signals :
    void imageUpdated();
    void previewImageUpdated();

private:
    enum class MouseEventType { press, move, release };
    /* fields */
    Global::Tool selectedTool;
    int selectedBrushSize;

    QPainter* painter;
    QPainter* previewPainter;
    QPen leftPen;
    QPen rightPen;
    QPen activePen;
    QPen eraserPen;
    QImage* previewImage;
    QImage* currentImage;

    QPointF startPoint;
    QPointF currentPoint;

    /* functions */
    void createLinePreview(QPointF point);
    void useTool(QPointF point, MouseEventType met);
    void setButton(int button);
    void penTool(QPointF point);
    void eraser(QPointF point);
    void lineTool(QPointF point);
    void fillTool(QPointF point);
    void recursiveFill(int x, int y);
    void brushTool(QPointF point);
};

#endif // TOOLS_H
