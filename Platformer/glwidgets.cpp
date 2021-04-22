#include "glwidgets.h"

GlWidget::GlWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

void GlWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
}

void GlWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -7.0);
    glTranslatef(0,0,0);

    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 1.0f); //green
        glVertex3f(-1.0f, 0.0f, 0.0f);
        glColor3f(0.0f, 0.8f, 0.0f); //blue
        glVertex3f( 1.0f, 0.0f, 0.0f);
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f( 0.0f, 1.732f, 1.0f);
    glEnd();

    glFlush();
}

void GlWidget::resizeGL(int w, int h){
    //set viewport
    glViewport(0,0,w,h);

    //initialize projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* multiply the current matrix by a perspective matrix
     * void glFrustum(GLdouble left, GLdouble right,GLdouble bottom,GLdouble top,GLdouble nearVal,GLdouble farVal);
     * left, right: Specify the coordinates for the left and right vertical clipping planes.
     * bottom, top: Specify the coordinates for the bottom and top horizontal clipping planes.
     * nearVal, farVal: Specify the distances to the near and far depth clipping planes. Both distances must be positive.
     */
    glFrustum(-2, +2, -2, +2, 4.0, 10.0);

    //initialize modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
