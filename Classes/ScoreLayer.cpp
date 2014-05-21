#include "ScoreLayer.h"

USING_NS_CC;
ScoreLayer::ScoreLayer()
{
}
ScoreLayer::~ScoreLayer(){}
//��ʼ������
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
//�Կؼ��Լ��������г�ʼ��
void  ScoreLayer::setupViews()
{
	CCLabelBMFont* scoreFont=CCLabelBMFont::create("Score:20","arial-14.fnt");
	scoreFont->setAnchorPoint(CCPointZero);
	scoreFont->setPosition(CCPointZero);
	scoreFont->setScale(1.5f);
	this->addChild(scoreFont);
}
//��ȡ����ָ��
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
 