#include "BasicLayer.h"



USING_NS_CC;
BasicLayer::BasicLayer(){}
BasicLayer::~BasicLayer(){}

//初始化方法
bool BasicLayer::init()
{
	
	bool sRect=false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		
		sRect = true;
	}while(0);
	return sRect;
}
//获取屏幕大小的方法
CCSize BasicLayer::getWinSize()
{
	return CCDirector::sharedDirector()->getWinSize();
}

void BasicLayer::setBackgroundImage(const char* back_image_name)
{
	CCSprite *sp = CCSprite::create( back_image_name );
	sp->setPosition(ccp(getWinSize().width/2,getWinSize().height/2));
	this->addChild(sp);
}
