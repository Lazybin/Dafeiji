#include "OptionLayer.h"
#include "WelcomeLayer.h"

USING_NS_CC;
OptionLayer::OptionLayer()
{
	music_status=true;
}
OptionLayer::~OptionLayer(){}
//初始化方法
bool OptionLayer::init()
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
void  OptionLayer::setupViews()
{
	setBackgroundImage("loading.png");

	//加入menutitle
	CCSprite* title=CCSprite::create("menuTitle.png",CCRectMake(0,0,133,36));
	title->setAnchorPoint(ccp(0.5,1));
	title->setPosition(ccp(getWinSize().width/2,getWinSize().height-20));
	this->addChild(title);

	CCMenuItemToggle* music_trigger = CCMenuItemToggle::createWithTarget(this, 
		 menu_selector(OptionLayer::setmusic_call_back), CCMenuItemFont::create( "Music : On" ),CCMenuItemFont::create("Music : Off"),NULL);
	if(SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		music_trigger->setSelectedIndex(1);
	}
	else
	{
		music_trigger->setSelectedIndex(0);
	}
	music_trigger->setPosition(ccp(getWinSize().width/2,getWinSize().height/2));
	
	//创建返回按钮
	CCLabelBMFont* fontOfBack=CCLabelBMFont::create("Go Back","arial-14.fnt");
	CCMenuItemLabel* backlabel=CCMenuItemLabel::create(fontOfBack,this,menu_selector(OptionLayer::back_callback));
	backlabel->setAnchorPoint(ccp(0.5,0));
	backlabel->setPosition(ccp(getWinSize().width/2,30));
	CCMenu* menu=CCMenu::create(music_trigger,backlabel,NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu);
}
void OptionLayer::back_callback(CCObject *pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f,WelcomeLayer::scene()));
}
void OptionLayer::setmusic_call_back(CCObject *pSender)
{
	


	if(music_status==true)
	{
		
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		music_status=false;
	    //status=SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying();
		CCLOG("AA");
	}
	else
	{
		music_status=true;
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		CCLOG("BB");
	}
	
}
//获取场景指针
CCScene* OptionLayer::scene()
{
	CCScene* sc=NULL;
	do
	{
		sc = CCScene::create();
		CC_BREAK_IF(!sc);
		OptionLayer * layer=OptionLayer::create();

		CC_BREAK_IF(!layer);

		sc->addChild(layer);
	}
	while(0);
	return sc;
}
 