#include "WelcomeLayer.h"
#include "OptionLayer.h"
#include "GameLayer.h"

USING_NS_CC;
WelcomeLayer::WelcomeLayer(){}
WelcomeLayer::~WelcomeLayer(){}
//初始化方法
bool WelcomeLayer::init()
{
	
	bool sRect=false;
	do
	{
		CC_BREAK_IF(!BasicLayer::init());

		setBackgroundImage("loading.png");
		setupViews();
		
		sRect = true;
	}while(0);
	return sRect;
}
void  WelcomeLayer::setupViews()
{
	//setBackgroundImage("loading.png");

	//加入菜单项
	//开始菜单
	CCSprite *pStartNormal=CCSprite::create("menu.png",CCRectMake(0,0,126,33));
	CCSprite *pStartPressed=CCSprite::create("menu.png",CCRectMake(0,33,126,33));
	CCSprite *pStartDisabled=CCSprite::create("menu.png",CCRectMake(0,66,126,33));

	CCMenuItemSprite *startGame=CCMenuItemSprite::create(pStartNormal,pStartPressed,pStartDisabled,this,menu_selector(WelcomeLayer::startgame_call_back));
	//选项菜单
	CCSprite *pOptionNormal=CCSprite::create("menu.png",CCRectMake(126,0,126,33));
	CCSprite *pOptionPressed=CCSprite::create("menu.png",CCRectMake(126,33,126,33));
	CCSprite *pOptionDisabled=CCSprite::create("menu.png",CCRectMake(126,66,126,33));

	CCMenuItemSprite *option=CCMenuItemSprite::create(pOptionNormal,pOptionPressed,pOptionDisabled,this,menu_selector(WelcomeLayer::option_call_back));
	CCMenu *pMenu=CCMenu::create(startGame,option,NULL);
	pMenu->setPosition(ccp(getWinSize().width/2,getWinSize().height/2+20));
	pMenu->alignItemsVerticallyWithPadding(10);
	this->addChild(pMenu);

	CCSprite *pLogo=CCSprite::create("logo.png");
	pLogo->setAnchorPoint(ccp(0.5,1));
	pLogo->setPosition(ccp(getWinSize().width/2,getWinSize().height));
	this->addChild(pLogo);
}
void WelcomeLayer::startgame_call_back(CCObject *pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f,GameLayer::scene()));
}
void WelcomeLayer::option_call_back(CCObject *pSender)
{
	//CCLOG("bb");
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f,OptionLayer::scene()));
}
//获取场景指针
CCScene* WelcomeLayer::scene()
{
	CCScene* sc=NULL;
	do
	{
		sc = CCScene::create();
		CC_BREAK_IF(!sc);
		WelcomeLayer * layer=WelcomeLayer::create();

		CC_BREAK_IF(!layer);

		sc->addChild(layer);
	}
	while(0);
	return sc;
}
 void WelcomeLayer::onEnter()
 {
	 CCLayer::onEnter();
	 //SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/mainMainMusic.mp3",true);
	 //SimpleAudioEngine::sharedEngine()->playBackgroundMusic("test.wav",true);
 }