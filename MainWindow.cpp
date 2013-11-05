#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	normalImage = NULL;
	filtredImage = NULL;
	connect(ui.loadImgButton,SIGNAL(clicked()),this,SLOT(loadNormalImage()));
	connect(ui.executeButton,SIGNAL(clicked()),this,SLOT(binarizeImage()));
	connect(ui.intensySlider,SIGNAL(valueChanged(int)),ui.intensyValue,SLOT(setNum(int)));
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
	ui.filePathLine->setText(getFilePath("C:"));
	if(normalImage) // if oldImage had existed before
		delete normalImage;
	normalImage =  new QImage(ui.filePathLine->text());
	ui.newImgLabel->clear();
	setLabelImg(normalImage->copy(),ui.oldImgLabel);
	setEnableLayoutIthems(ui.executeHLayout,true);
}

void MainWindow::binarizeImage()
{
	if(normalImage) // if image didn't load function can't binarize
	{
		if(filtredImage) // if newImage had existed before
			delete filtredImage;
		filtredImage = new QImage(normalImage->copy());
		if(ui.comboBox->currentText() == "ASM")
			Filter::asmBinaryzation(filtredImage,ui.intensySlider->value());
		else
			Filter::cppBinaryzation(filtredImage, ui.intensySlider->value());

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


