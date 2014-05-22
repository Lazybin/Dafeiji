#include "GameOverLayer.h"
#include "WelcomeLayer.h"
#include "GameLayer.h"

USING_NS_CC;
GameOverLayer::GameOverLayer()
{
}
GameOverLayer::~GameOverLayer(){}
//初始化方法
bool GameOverLayer::init()
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
//对控件以及布景进行初始化
void  GameOverLayer::setupViews()
{
	setBackgroundImage("loading.png");

	//加入menutitle
	CCSprite* title=CCSprite::create("gameOver.png");
	title->setAnchorPoint(ccp(0.5,1));
	title->setPosition(ccp(getWinSize().width/2,getWinSize().height-60));
	this->addChild(title);

	CCLabelBMFont* fontOfScore=CCLabelBMFont::create("SCORE:40982","fonts/bitmapFontTest.fnt");
	fontOfScore->setPosition(ccp(getWinSize().width/2,getWinSize().height/2+50));
	this->addChild(fontOfScore);

	CCSprite *pPlayAgainNormal=CCSprite::create("menu.png",CCRectMake(378,0,126,33));
	CCSprite *pPlayAgainPressed=CCSprite::create("menu.png",CCRectMake(378,33,126,33));
	CCSprite *pPlayAgainDisabled=CCSprite::create("menu.png",CCRectMake(378,66,126,33));

	CCMenuItemSprite *playagain=CCMenuItemSprite::create(pPlayAgainNormal,pPlayAgainPressed,pPlayAgainDisabled,this,menu_selector(GameOverLayer::play_again_callback));
	
	
	//创建返回按钮
	CCLabelBMFont* fontOfBack=CCLabelBMFont::create("Go Back","arial-14.fnt");
	CCMenuItemLabel* backlabel=CCMenuItemLabel::create(fontOfBack,this,menu_selector(GameOverLayer::back_callback));
	CCMenu *pMenu=CCMenu::create(playagain,backlabel,NULL);
	pMenu->setPosition(ccp(getWinSize().width/2,getWinSize().height/3+60));
	pMenu->alignItemsVerticallyWithPadding(10);
	this->addChild(pMenu);
	/*CCMenu* menu=CCMenu::create(backlabel,NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu);*/
}
void GameOverLayer::play_again_callback(CCObject *pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f,GameLayer::scene()));
}
void GameOverLayer::back_callback(CCObject *pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f,WelcomeLayer::scene()));
}
//获取场景指针
CCScene* GameOverLayer::scene()
{
	CCScene* sc=NULL;
	do
	{
		sc = CCScene::create();
		CC_BREAK_IF(!sc);
		GameOverLayer * layer=GameOverLayer::create();

		CC_BREAK_IF(!layer);

		sc->addChild(layer);
	}
	while(0);
	return sc;
}