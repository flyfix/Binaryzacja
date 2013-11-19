#ifndef FILTER_H_
#define FILTER_H_
#include <QColor>
#include <QImage>
class Filter
{
public:
	static void cppBinaryzation(QImage * source , int intense);
	static void cBinaryzation(QImage * source, int intense);
	static double cppAvgLum(QImage * source);
	static double cAvgLum(QImage * source);
	
private:
	static void convertToRgb32(QImage * source);
	static double intensityValue(int r, int g, int b);


};


#endif
