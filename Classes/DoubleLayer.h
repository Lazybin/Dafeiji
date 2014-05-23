#ifndef __DOUBLELAYER_H__
#define __DOUBLELAYER_H__
#include "cocos2d.h"
#include "BasicLayer.h"
USING_NS_CC;
class DoubleLayer:public BasicLayer
{
public:
	virtual bool init();
	CREATE_FUNC(DoubleLayer);
	void setupViews();
	void finishMoveCallback(CCNode *pSender);
	void addDouble(CCPoint point); 
	CCSpriteBatchNode *mDoubleBatchNode;
	CCArray* doubleArray;
};
#endif // __DOUBLELAYER_H__