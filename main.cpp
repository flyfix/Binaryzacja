#include "binaryzacja.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Binaryzacja mainWindow = new Binaryzacja();
	mainWindow.show();
	return app.exec();
}
