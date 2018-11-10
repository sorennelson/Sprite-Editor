#ifndef PROJECT_H
#define PROJECT_H

#include <QPixmap>
#include <QLabel>
#include <QFileDialog>
#include "canvas.h"
#include "tools.h"
#include "spriteanimation.h"
#include "colorlabel.h"


class Project: public QObject
{
    Q_OBJECT

public:
    Project();

    virtual ~Project();

    void setCurrentFrame(int frameNumber);

    void nextFrame();

    QImage* createNewFrame();

    void addNewFrame();

    void setActiveTool(Global::Tool tool);

    SpriteAnimation* getAnimation();

    Canvas* getCanvas();

    void handleGridlinesToggled();

    void handleAnimationSliderValueChanged(int value);

    void setColorLabel(ColorLabel* leftLabel, ColorLabel* rightLabel);

    void save(QString filename);

    void load(QString filename);

    void exportGIF(QString filename);

public slots:
    void updateImage();

    void handleColorChanged(QColor color, ColorLabel* label);

    void updatePreviewImage();

private:
    std::vector<QImage*> frames;
    QImage* previewImage;
    int currentFrame;

    SpriteAnimation* animation;

    Tools* tools;

    Canvas* canvas;

    ColorLabel* leftColorLabel;
    ColorLabel* rightColorLabel;

    void setColorLabelColor(QColor color);

};

#endif // PROJECT_H
