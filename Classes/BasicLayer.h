#ifndef __BASICLAYER_H__
#define __BASICLAYER_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace CocosDenshion;
class BasicLayer : public CCLayer
{
public:
	BasicLayer();
	~BasicLayer();
    
    virtual bool init();

	CCSize getWinSize();

	void setBackgroundImage(const char * back_image_name);
    
    CREATE_FUNC(BasicLayer);
};

#endif // __BASICLAYER_H__