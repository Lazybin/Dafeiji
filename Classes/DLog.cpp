#include "DLog.h"

DLog::DLog(){}
DLog::~DLog(){}


void DLog::d( const char* content)
{
	if(flag)
		CCLOG("LOG==>%s",content);
}