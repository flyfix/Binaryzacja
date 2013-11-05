#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H


#include <QtWidgets/QFileDialog>
#include <QtWidgets/QLayout>
#include <QRgb>
#include "Debug.h"
#include "Filter.h"
#include "ui_binaryzacja.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void loadNormalImage(); // Load old image to frame
	void binarizeImage(); // Load new(filtered) image to frame


private:
	Ui::BinaryzacjaClass ui;
	QImage * filtredImage;
	QImage * normalImage;
	QString getFilePath(QString dirPath = "C:" ,QString fileFilter = ""); 
	void setLabelImg(QImage source, QLabel * destination, bool scaleToWidth = true);
	void setEnableLayoutIthems(QLayout * layout, bool enable = true);
};

#endif // BINARYZACJA_H
