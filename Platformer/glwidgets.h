#ifndef GLWIDGETS_H
#define GLWIDGETS_H

#include <QtWidgets>
#include <QtOpenGL>
#include <GL/glu.h>

class GlWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GlWidget(QWidget *parent = 0);

    void moveObject(int objectID, float x, float y, float z);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);



};

#endif // GLWIDGETS_H
