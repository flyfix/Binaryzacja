#ifndef FILTER_H_
#define FILTER_H_
#include <QColor>
#include <QImage>
class Filter
{
public:
	static void cppBinaryzation(QImage * source , int intense);
	static void asmBinaryzation(QImage * source , int intense); //FIXME wrong arguments push to assambler
private:
	static void convertToRgb32(QImage * source);
	static int intensityValue(int r, int g, int b);
};


#endif
