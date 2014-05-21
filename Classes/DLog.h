#ifndef __DLOG_H__
#define __DLOG_H__

#include "cocos2d.h"
USING_NS_CC;
// LOG π§æﬂ¿‡
class DLog
{
public:
	DLog();
	~DLog();
	const static bool flag=true;
	static void d( const char* content);
};

#endif // __DLOG_H__