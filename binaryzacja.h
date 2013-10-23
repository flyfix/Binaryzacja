#ifndef BINARYZACJA_H
#define BINARYZACJA_H


#include <QtWidgets/QFileDialog>
#include "ui_binaryzacja.h"

class Binaryzacja : public QMainWindow
{
	Q_OBJECT

public:
	Binaryzacja(QWidget *parent = 0);
	~Binaryzacja();

private:
	Ui::BinaryzacjaClass ui;

	QString getFilePath(QString dirPath = "C:" ,QString fileFilter = ""); 
};

#endif // BINARYZACJA_H
