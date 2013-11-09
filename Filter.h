#ifndef FILTER_H_
#define FILTER_H_
#include <QColor>
#include <QImage>
class Filter
{
public:
	static void cppBinaryzation(QImage * source , int intense);
	static void cppPtrBinaryzation(QImage * source, int intense);
private:
	static void convertToRgb32(QImage * source);
	static int intensityValue(int r, int g, int b);
};


#endif
