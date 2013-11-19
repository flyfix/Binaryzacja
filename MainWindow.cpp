#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	normalImage = NULL;
	filtredImage = NULL;
	timer = new QTime();
	connect(ui.loadImgButton,SIGNAL(clicked()),this,SLOT(loadNormalImage()));
	connect(ui.intensySlider,SIGNAL(valueChanged(int)),ui.intensyLabel,SLOT(setNum(int)));
	connect(ui.intensySlider,SIGNAL(valueChanged(int)),this,SLOT(binarizeImage(int)));
	connect(ui.autoLevelButton,SIGNAL(clicked()),this,SLOT(autoLevel()));


}

MainWindow::~MainWindow()
{
	delete filtredImage;
	delete normalImage;
}

QString MainWindow::getFilePath(QString dirPath ,QString fileFilter)
{
		QString path = QFileDialog::getOpenFileName(this,"Open File",dirPath,fileFilter);
		return path;
}
void MainWindow::loadNormalImage()
{
	ui.filePathLine->setText(getFilePath("C:/Users/Klaudiusz/Desktop/testImages"));
	if(normalImage) // if oldImage had existed before
		delete normalImage;
	normalImage =  new QImage(ui.filePathLine->text());
	ui.newImgLabel->clear();
	if(normalImage->bitPlaneCount() < 24)
	{
		ui.statusBar->showMessage("Wrong image format. Image should be bmp24 or better" , 3000);
	}
	else
	{
		setLabelImg(normalImage->copy(),ui.oldImgLabel);
		setEnableLayoutIthems(ui.executeHLayout,true);
		ui.statusBar->showMessage("Image load correctly" , 3000);
	}
	

}

void MainWindow::binarizeImage(int intensy)
{
	if(normalImage) // if image didn't load function can't binarize
	{
		if(filtredImage) // if newImage had existed before
			delete filtredImage;
		filtredImage = new QImage(normalImage->copy());
		if(ui.comboBox->currentText() == "ASM")
		{
			timer->start();
			asmBinaryzation(static_cast<unsigned char*>(filtredImage->bits()),filtredImage->height()*filtredImage->width(),intensy);

		}
		else if(ui.comboBox->currentText() == "C++")
		{
			timer->start();
			Filter::cppBinaryzation(filtredImage,intensy);
		}
		else
		{
			timer->start();
			Filter::cBinaryzation(filtredImage,intensy);;
		}
		ui.statusBar->showMessage("Converting takes " + QString::number(timer->elapsed()) + " milliseconds",3000);
		setLabelImg(filtredImage->copy(), ui.newImgLabel);
	}
}

void MainWindow::autoLevel()
{
	if(normalImage) // if image didn't load function can't binarize
	{
		int avgLuminanceLevel;

		if(ui.comboBox->currentText() == "ASM")
		{
			timer->start();
			avgLuminanceLevel = asmAvgLum(filtredImage->bits(), filtredImage->height()*filtredImage->width());

		}
		else if(ui.comboBox->currentText() == "C++")
		{
			timer->start();
			avgLuminanceLevel = Filter::cppAvgLum(normalImage);
		}
		else
		{
			timer->start();
			avgLuminanceLevel = Filter::cAvgLum(normalImage);
		}
		ui.statusBar->showMessage("Computing auto level takes " + QString::number(timer->elapsed()) + " milliseconds",3000);
		ui.intensySlider->setValue(avgLuminanceLevel);
		setLabelImg(filtredImage->copy(), ui.newImgLabel);
	}
}

void MainWindow::setLabelImg(QImage source, QLabel * destination, bool scaleToWidth)
{
		if(scaleToWidth)
			destination->setPixmap(QPixmap::fromImage(source).scaledToWidth(ui.oldImgLabel->size().width()));
		else
			destination->setPixmap(QPixmap::fromImage(source));
}

void MainWindow::setEnableLayoutIthems(QLayout * layout, bool enable)
{
	
	for(int i = 0 ; i < layout->count() ; i++)
		layout->itemAt(i)->widget()->setEnabled(enable);
	
}