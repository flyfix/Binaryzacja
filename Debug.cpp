#include "Debug.h"

bool Debug::status = false;

Debug & Debug::getInstance()
{
		static Debug instance;
		return instance;
}

void Debug::print(QString msg)
{
	if(status)
		qDebug() << msg;
}

bool Debug::setStatus(bool stat)
{
	status = stat;
	return status;
}