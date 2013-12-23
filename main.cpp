#include "stdafx.h"
#include "geolab.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Geolab w;
	w.show();
	return a.exec();
}
