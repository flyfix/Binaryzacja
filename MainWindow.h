#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H


#include <QtWidgets/QFileDialog>
#include <QtWidgets/QLayout>
#include <QTime>
#include <QRgb>
#include "Filter.h"
#include "ui_binaryzacja.h"
#include "asm.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
public slots:
	void loadNormalImage(); // Load old image to frame
	void binarizeImage(int intensy); // Load new(filtered) image to frame
	void autoLevel(); // Load new(filtered) image to frame


private:
	QTime * timer;
	Ui::BinaryzacjaClass ui;
	QImage * filtredImage;
	QImage * normalImage;
	QString getFilePath(QString dirPath = "C:" ,QString fileFilter = ""); 
	void setLabelImg(QImage source, QLabel * destination, bool scaleToWidth = true);
	void setEnableLayoutIthems(QLayout * layout, bool enable = true);
};

#endif // BINARYZACJA_H
