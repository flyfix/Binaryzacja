#ifndef BINARYZACJA_H
#define BINARYZACJA_H


#include <QtWidgets/QFileDialog>
#include <QRgb>
#include "Debug.h"
#include "Filter.h"
#include "ui_binaryzacja.h"

class Binaryzacja : public QMainWindow
{
	Q_OBJECT

public:
	Binaryzacja(QWidget *parent = 0);
	~Binaryzacja();

public slots:
	void setOldImg(); // Load old image to frame
	void setNewImage(); // Load new(filtred) image to frame


private:
	Ui::BinaryzacjaClass ui;
	QImage * oldImage;
	QImage * newImage;
	QString getFilePath(QString dirPath = "C:" ,QString fileFilter = ""); 
	void setLabelImg(QImage source, QLabel * destination, bool scaleToWidth = true);
};

#endif // BINARYZACJA_H
