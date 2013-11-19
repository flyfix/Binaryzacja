#include "Filter.h"


double Filter::intensityValue(int r, int g, int b)
{
    return 0.299*r + 0.587*g + 0.1140000000000001*b;
}

double Filter::cAvgLum(QImage * source)
{
	int imageSizeInBytes = source->height() * source->width() * 4;
	unsigned char * pixelData = source->bits();
	double totalLuminance = 0;

	for(int i = 0 ; i < imageSizeInBytes ; i += 4)
	{
		totalLuminance += intensityValue(pixelData[i + 2],pixelData[i+1],pixelData[i]);
	}

	return totalLuminance/imageSizeInBytes;
}

double Filter::cppAvgLum(QImage * source)
{
	QColor color;
	*source  = source->convertToFormat(QImage::Format_ARGB32_Premultiplied);
	int imageSizeInBytes = source->height() * source->width() * 4;
	unsigned char * pixelData = source->bits();
	double totalLuminance = 0;
	for(int x = 0 ; x < source->width() ; x++)
	{
		for(int y = 0 ; y < source->height() ; y++)
		{
			QPoint p(x,y);
			color.setRgb(source->pixel(p));
			totalLuminance = intensityValue(color.red(), color.green(), color.blue());
			
		}
	}

	return totalLuminance/imageSizeInBytes;
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

void Filter::cBinaryzation(QImage * source, int intense) // TODO
{

	int imageSizeInBytes = source->height() * source->width() * 4;
	unsigned char * pixelData = source->bits();

	for(int i = 0 ; i < imageSizeInBytes ; i += 4)
	{
		if(intensityValue(pixelData[i+2], pixelData[i+1], pixelData[i]) < intense)
			pixelData[i] = pixelData[i+1] = pixelData[i+2] = 0;
		else
			pixelData[i] = pixelData[i+1] = pixelData[i+2] = 255;
	}
}