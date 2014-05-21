#include "PauseLayer.h"

USING_NS_CC;
PauseLayer::PauseLayer()
{
}
PauseLayer::~PauseLayer(){}
//��ʼ������
bool PauseLayer::init()
{
	
	if(!CCLayerColor::initWithColor(ccc4(0,0,0,50)))
	{
		return false;
	}
		setupViews();
		
	return true;
}
//�Կؼ��Լ��������г�ʼ��
void  PauseLayer::setupViews()
{
	//create menu
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCMenuItemImage* resumeItem=CCMenuItemImage::create("play.png","play.png",this,menu_selector(PauseLayer::play_logic));
	resumeItem->setPosition(ccp(size.width/2,size.height/2));

	CCMenu* menu=CCMenu::create(resumeItem,NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu);
}
//��ȡ����ָ��
CCScene* PauseLayer::scene()
{
	CCScene* sc=NULL;
	do
	{
		sc = CCScene::create();
		CC_BREAK_IF(!sc);
		PauseLayer * layer=PauseLayer::create();

		CC_BREAK_IF(!layer);

		sc->addChild(layer);
	}
	while(0);
	return sc;
}
void PauseLayer::play_logic(CCObject* pSender)
{

	CCLayer* parentNode=(CCLayer*)getParent();
	parentNode->getChildByTag(156)->setVisible(true);
	this->setVisible(false);
	CCDirector::sharedDirector()->resume();
}
 