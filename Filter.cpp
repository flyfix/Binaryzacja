#include "Filter.h"


int Filter::intensityValue(int r, int g, int b)
{
    return 0.299*r + 0.587*g + 0.1140000000000001*b;
}
void Filter::cppBinaryzation(QImage * source, int intense) // TODO
{
	QColor color;
	*source  = source->convertToFormat(QImage::Format_ARGB32_Premultiplied);
	for(int x = 0 ; x < source->width() ; x++)
	{
		for(int y = 0 ; y < source->height() ; y++)
		{
			QPoint p(x,y);
			color.setRgb(source->pixel(p));
			if(intensityValue(color.red(), color.green(), color.blue()) < intense)
			{
				color.setRed(0);
				color.setGreen(0);
				color.setBlue(0);
			}
			else
			{
				color.setRed(255);
				color.setGreen(255);
				color.setBlue(255);
			}
			source->setPixel(p,color.rgb());
			}
	}
}