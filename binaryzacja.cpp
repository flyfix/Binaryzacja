#include "binaryzacja.h"

Binaryzacja::Binaryzacja(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Binaryzacja::~Binaryzacja()
{
	
}

QString Binaryzacja::getFilePath(QString dirPath ,QString fileFilter)
{
		QString path = QFileDialog::getOpenFileName(this,"Open File",dirPath,fileFilter);
		return path;
}



