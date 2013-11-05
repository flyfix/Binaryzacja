#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	newImage = NULL;
	oldImage = NULL;
	connect(ui.loadImgButton,SIGNAL(clicked()),this,SLOT(setOldImg()));
	connect(ui.executeButton,SIGNAL(clicked()),this,SLOT(setNewImage()));
	connect(ui.intensySlider,SIGNAL(valueChanged(int)),ui.intensyValue,SLOT(setNum(int)));
}

MainWindow::~MainWindow()
{
	delete oldImage;
	delete newImage;
}

QString MainWindow::getFilePath(QString dirPath ,QString fileFilter)
{
		QString path = QFileDialog::getOpenFileName(this,"Open File",dirPath,fileFilter);
		return path;
}
//QImage MainWindow::LoadQImageFromFile(QString path)
//{
//	return new QImage(path);
//}

void MainWindow::setOldImg()
{
	ui.filePathLine->setText(getFilePath("C:","*.bmp"));
	if(oldImage) // if oldImage had existed before
		delete oldImage;
	oldImage =  new QImage(ui.filePathLine->text());
	setLabelImg(oldImage->copy(),ui.oldImgLabel);
}

void MainWindow::setNewImage()
{
	if(newImage) // if newImage had existed before
		delete newImage;
	newImage = new QImage(oldImage->copy());
	if(ui.comboBox->currentText() == "ASM")
		Filter::asmBinaryzation(newImage,ui.intensySlider->value());
	else
		Filter::cppBinaryzation(newImage, ui.intensySlider->value());

	setLabelImg(newImage->copy(), ui.newImgLabel);
}

void MainWindow::setLabelImg(QImage source, QLabel * destination, bool scaleToWidth)
{
		if(scaleToWidth)
			destination->setPixmap(QPixmap::fromImage(source).scaledToWidth(ui.oldImgLabel->size().width()));
		else
			destination->setPixmap(QPixmap::fromImage(source));
}
	

