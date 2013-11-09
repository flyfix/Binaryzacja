#include "Filter.h"


int Filter::intensityValue(int r, int g, int b)
{
    return 0.299*r + 0.587*g + 0.1140000000000001*b;
}

void Filter::cppBinaryzation(QImage * source, int intense)
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

void Filter::cppPtrBinaryzation(QImage * source, int intense) // TODO
{

	int bitsPerPixel = source->bitPlaneCount();
	int height = source->height();
	int width = source->width();
	unsigned char * pixelData = source->bits();

	//24 Bitmap, PNG , JPG ...  pixel have BGRA format
	if(bitsPerPixel >= 24)
		for(int i = 0 ; i < height*width * 4 ; i += 4)
		{
			if(intensityValue(pixelData[i+2], pixelData[i+1], pixelData[i]) < intense)
				pixelData[i] = pixelData[i+1] = pixelData[i+2] = 0;
			else
				pixelData[i] = pixelData[i+1] = pixelData[i+2] = 255;
		}
}