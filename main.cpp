#include "MainWindow.h"
#include "Debug.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	Debug::setStatus(false); // On console debugging
	QApplication app(argc, argv);
	MainWindow mainWindow = new MainWindow();
	mainWindow.show();
	return app.exec();
}
