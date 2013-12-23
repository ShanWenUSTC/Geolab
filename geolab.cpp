#include "stdafx.h"
#include "geolab.h"


Geolab::Geolab(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//design size and position of mainwindow
	setGeometry(400, 100, 700, 500);

	//design window title
	setWindowTitle(tr("Geolab beta"));

	// design widgets
	DesignAction();
	DesignMenubar();
	DesignToolbar();
	DesignStatusbar();

	//design openGL window
	pGL = new myOpenGL (this);
	pGL->move(0, ui.menuBar->height()+ui.mainToolBar->height());
}

Geolab::~Geolab()
{

}

void Geolab::resizeEvent(QResizeEvent *e)
{
	pGL->resize( e->size().width(), e->size().height()-menuBar()->height()
		-ui.mainToolBar->height()-statusBar()->height() ); 
}

void Geolab::DesignAction()
{
	open_action_ = new QAction(QIcon(":/images/doc-open"), tr("&Open..."),this);
	open_action_->setShortcut(QKeySequence::Open);
	open_action_->setStatusTip(tr("Open an existing file"));
	connect(open_action_, &QAction::triggered, this, &Geolab::Open);
}

void Geolab::DesignMenubar()
{
	QMenu *menufile = ui.menuBar->addMenu(tr("File"));
	menufile->addAction(open_action_);
}

void Geolab::DesignStatusbar()
{
	ui.statusBar->addAction(open_action_);
}

void Geolab::DesignToolbar()
{
	ui.mainToolBar->addAction(open_action_);
}

void Geolab::Open()
{

}
