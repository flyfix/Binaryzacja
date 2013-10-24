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

public slots:
	void setOldImg();
	void setNewImage();


private:
	Ui::BinaryzacjaClass ui;
	QImage * oldImage;
	QImage * newImage;
	QString getFilePath(QString dirPath = "C:" ,QString fileFilter = ""); 
	void setLabelImg(QImage source, QLabel * destination, bool scaleToWidth = true);
	QImage cppBinaryzation(QImage source , int intense);
	QImage asmBinaryzation(QImage source , int intense); //FIXME wrong arguments push to assambler

};

#endif // BINARYZACJA_H
