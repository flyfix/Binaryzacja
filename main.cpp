#include "binaryzacja.h"
#include "Debug.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	Debug::setStatus(false); // On console debugging
	QApplication app(argc, argv);
	Binaryzacja mainWindow = new Binaryzacja();
	mainWindow.show();
	return app.exec();
}
