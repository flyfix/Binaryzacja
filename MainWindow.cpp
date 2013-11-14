#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	normalImage = NULL;
	filtredImage = NULL;
	connect(ui.loadImgButton,SIGNAL(clicked()),this,SLOT(loadNormalImage()));
	connect(ui.intensySlider,SIGNAL(valueChanged(int)),ui.intensyLabel,SLOT(setNum(int)));
	connect(ui.intensySlider,SIGNAL(valueChanged(int)),this,SLOT(binarizeImage(int)));
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
	setLabelImg(normalImage->copy(),ui.oldImgLabel);
	setEnableLayoutIthems(ui.executeHLayout,true);
}

void MainWindow::binarizeImage(int intensy)
{
	if(normalImage) // if image didn't load function can't binarize
	{
		if(filtredImage) // if newImage had existed before
			delete filtredImage;
		filtredImage = new QImage(normalImage->copy());
		if(ui.comboBox->currentText() == "ASM")
			asmBinaryzation(reinterpret_cast<unsigned char*>(filtredImage->bits()),filtredImage->height()*filtredImage->width(),intensy);
		else if(ui.comboBox->currentText() == "C++")
			Filter::cppBinaryzation(filtredImage,intensy);
		else
			Filter::cppPtrBinaryzation(filtredImage,intensy);

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
