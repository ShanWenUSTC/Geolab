#include "stdafx.h"
#include "myOpenGL.h"

#define DRAG_POINT 1
#define ADD_POINT 0

myOpenGL::myOpenGL(QWidget *parent)
    :QGLWidget(parent)
{
 
}

myOpenGL::~myOpenGL()
{

}

void myOpenGL::initializeGL()
{
    // enable smooth shading
    glShadeModel( GL_SMOOTH );

    // set clear color
    glClearColor( 0.5f, 0.5f, 0.5f, 0.0 );

    // set depth buffer
    glClearDepth( GL_DEPTH_TEST );
}

void myOpenGL::resizeGL(int width, int height)
{
    if( height == 0 )
    {
        height = 1;
    }

    //    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);


    //    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    //    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

   // reset current viewport
   glViewport( 0, 0, (GLint)width, (GLint)height );

   // set projection matrix
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();

   if (width <= height)
   {
       x_max_ = 5.0;
       y_max_ = 5.0*(GLfloat)height/(GLfloat)width;
       glOrtho(-x_max_, x_max_, -y_max_, y_max_, -1.0, 1.0);
   }
   else
   {
       x_max_ = 5.0*(GLfloat)width/(GLfloat)height;
       y_max_ = 5.0;
       glOrtho(-x_max_, x_max_, -y_max_, y_max_, -1.0, 1.0);
   }
}

void myOpenGL::paintGL()
{
    // clear screen and depth buffer
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void myOpenGL::mousePressEvent(QMouseEvent *e)
{
    switch(e->button())
    {
    case Qt::LeftButton:

        break;

    case Qt::RightButton:

        break;

    default:
        break;
    }
}

void myOpenGL::mouseMoveEvent(QMouseEvent *e)
{
    switch(e->buttons())
    {
    case Qt::RightButton:
  
        break;

    default:
        break;
    }
}

void myOpenGL::Clear()
{
    updateGL();
}



