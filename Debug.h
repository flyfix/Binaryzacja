#ifndef DEBUG_H
#define DEBUG_H

#include <QDebug>
//#include <QString>

// Singleton class to Debug
class Debug
{
public:
	static Debug & getInstance();
	static void print(QString msg);
	static void print(int msg);
	static bool setStatus(bool stat);
private:
	Debug() {}
	Debug(Debug const&);
	void operator=(Debug const&);
	static bool status;

};

#endif