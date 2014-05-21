#include "WarriorLayer.h"
WarriorLayer::WarriorLayer(){}
WarriorLayer::~WarriorLayer()
{
	m_warrrior=NULL;
}
    
bool WarriorLayer::init()
{
	if(!BasicLayer::init())
		return false;
	setupViews();
	return true;
}
void WarriorLayer::setupViews()
{
	this->m_warrrior=CCSprite::create("ship01.png",CCRect(60,0,60,40));
	m_warrrior->setPosition(ccp(getWinSize().width/2,50));
	this->addChild(m_warrrior);

	CCAnimation*  animation=CCAnimation::create();
	animation->setDelayPerUnit(0.1f);
	animation->addSpriteFrame(CCSpriteFrame::create("ship01.png",CCRect(60,0,60,40)));
	animation->addSpriteFrame(CCSpriteFrame::create("ship01.png",CCRect(0,0,60,40)));
	//animation->addSpriteFrame(CCSpriteFrame::create("ship01.png",CCRect(0,40,60,40)));
	CCAnimate* animate=CCAnimate::create(animation);
	m_warrrior->runAction(CCRepeatForever::create(animate));
	 

	this->setTouchEnabled(true);
	
}
CCSize WarriorLayer::getHeroSize()
{
	return m_warrrior->getContentSize();
}
CCPoint WarriorLayer::getHeroPosition()
{
	return m_warrrior->getPosition();
}

bool WarriorLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    
   touchBeganPosition=pTouch->getLocation();
   heroBeganPosition=m_warrrior->getPosition();
	
	//CCActionInterval* moveTo = CCMoveTo::create(0.2f,p);
   // m_warrrior->runAction( moveTo );
    
    
    //  修改为返回false  如果为true 则PauseLayer 的CCMenu 获取不到点击事件
    return true;
}
void WarriorLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint touchPoint = pTouch->getLocation();
	float x=heroBeganPosition.x+(touchPoint.x-touchBeganPosition.x);
	float y=heroBeganPosition.y+(touchPoint.y-touchBeganPosition.y);
	CCSize size= m_warrrior->getContentSize();
	if(x+size.width/2>getWinSize().width)
		x=getWinSize().width-size.width/2;
	else if(x-size.width/2<0)
		x=size.width/2;

	if(y+size.height/2>getWinSize().height)
		y=getWinSize().height-size.height/2;
	else if(y-size.height/2<0)
		y=size.height/2;
    m_warrrior->setPosition( ccp(x, y) );
}

void WarriorLayer::registerWithTouchDispatcher(void){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true	);
}