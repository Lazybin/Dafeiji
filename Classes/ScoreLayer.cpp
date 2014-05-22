#include "ScoreLayer.h"

USING_NS_CC;
ScoreLayer::ScoreLayer()
{
	this->m_score=0;
}
ScoreLayer::~ScoreLayer(){}
//初始化方法
bool ScoreLayer::init()
{
	
	bool sRect=false;
	do
	{
		CC_BREAK_IF(!BasicLayer::init());
		setupViews();
		
		sRect = true;
	}while(0);
	return sRect;
}
//对控件以及布景进行初始化
void  ScoreLayer::setupViews()
{
	this->scoreFont=CCLabelBMFont::create("Score:0","arial-14.fnt");
	
	scoreFont->setAnchorPoint(CCPointZero);
	scoreFont->setPosition(CCPointZero);
	scoreFont->setScale(1.5f);
	this->addChild(scoreFont);
}
//获取场景指针
CCScene* ScoreLayer::scene()
{
	CCScene* sc=NULL;
	do
	{
		sc = CCScene::create();
		CC_BREAK_IF(!sc);
		ScoreLayer * layer=ScoreLayer::create();

		CC_BREAK_IF(!layer);

		sc->addChild(layer);
	}
	while(0);
	return sc;
}
void ScoreLayer::updateScore(int score)
{
	this->m_score+=score;
	char strScore[100];
	sprintf(strScore,"Score:%d",this->m_score);
	this->scoreFont->setString(strScore,TRUE);
}
 