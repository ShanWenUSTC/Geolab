#ifndef MYOPENGL_H
#define MYOPENGL_H

#include <QGLWidget>
#include <QMouseEvent>

class myOpenGL : public QGLWidget
{
    Q_OBJECT

public:
    myOpenGL(QWidget *parent = 0);
    ~myOpenGL();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent *);

	void Clear();

private:
	int x_max_;
	int y_max_;
};

#endif // MYOPENGL_H
