#include "binaryzacja.h"

Binaryzacja::Binaryzacja(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	newImage = NULL;
	oldImage = NULL;
	connect(ui.loadImgButton,SIGNAL(clicked()),this,SLOT(setOldImg()));
	connect(ui.executeButton,SIGNAL(clicked()),this,SLOT(setNewImage()));
}

Binaryzacja::~Binaryzacja()
{
	delete oldImage;
	delete newImage;
}

QString Binaryzacja::getFilePath(QString dirPath ,QString fileFilter)
{
		QString path = QFileDialog::getOpenFileName(this,"Open File",dirPath,fileFilter);
		return path;
}

void Binaryzacja::setOldImg()
{
	ui.filePathLine->setText(getFilePath("C:","*.bmp"));
	if(oldImage) // if oldImage had existed before
		delete oldImage;
	oldImage =  new QImage(ui.filePathLine->text());
	setLabelImg(*oldImage,ui.oldImgLabel);
}

void Binaryzacja::setNewImage()
{
	if(newImage) // if newImage had existed before
		delete newImage;
	newImage = new QImage(cppBinaryzation(*oldImage, ui.intensySlider->value()));
	setLabelImg(*newImage, ui.newImgLabel);
}


QImage Binaryzacja::cppBinaryzation(QImage source, int intense) // TODO
{
	return source.copy();
}

void Binaryzacja::setLabelImg(QImage source, QLabel * destination, bool scaleToWidth)
{
		if(scaleToWidth)
			destination->setPixmap(QPixmap::fromImage(source).scaledToWidth(ui.oldImgLabel->size().width()));
		else
			destination->setPixmap(QPixmap::fromImage(source));
}
	


