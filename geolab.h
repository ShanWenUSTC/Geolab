#ifndef GEOLAB_H
#define GEOLAB_H

#include <QtWidgets/QMainWindow>
#include "ui_geolab.h"
#include "myOpenGL.h"

class Geolab : public QMainWindow
{
	Q_OBJECT

public:
	Geolab(QWidget *parent = 0);
	~Geolab();

	void resizeEvent(QResizeEvent *);

private:
	void DesignMenubar();
	void DesignToolbar();
	void DesignStatusbar();
	void DesignAction();

	void Open();

	Ui::GeolabClass ui;
	myOpenGL* pGL;
	QAction* open_action_;
};

#endif // GEOLAB_H
