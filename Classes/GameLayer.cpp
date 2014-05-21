#include "GameLayer.h"
#include "ScoreLayer.h"
#include "PauseLayer.h"
#include "Effects.h"
#include "Enemy.h"
USING_NS_CC;
GameLayer::GameLayer()
{
}
GameLayer::~GameLayer(){}
//初始化方法
bool GameLayer::init()
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
void  GameLayer::setupViews()
{
	//设置背景
	CCSprite* bg1=CCSprite::create("bg01.jpg");
	CCSprite* bg2=CCSprite::create("bg01.jpg");
	bg1->setAnchorPoint(CCPointZero);
	bg2->setAnchorPoint(CCPointZero);

	bg1->setPosition(CCPointZero);
	bg2->setPosition(ccp(0,576));
	this->addChild(bg1,0,11);
	this->addChild(bg2,0,12);
	//背景滚动
	this->schedule(schedule_selector(GameLayer::background_scroll_logic),0.01f);
	//创建分数层
	ScoreLayer* scoreLayer=ScoreLayer::create();
	scoreLayer->setAnchorPoint(ccp(0,1));
	scoreLayer->setPosition(ccp(10,getWinSize().height-20));
	this->addChild(scoreLayer);
	//创建暂停按钮
	CCMenuItemImage* pauseItem=CCMenuItemImage::create(	"pause.png","pause.png",this,menu_selector(GameLayer::pause_logic));
	pauseItem->setPosition(ccp(getWinSize().width-pauseItem->getContentSize().width-20,getWinSize().height-20));
	pauseItem->setAnchorPoint(ccp(0,1));

	CCMenu* menu=CCMenu::create(pauseItem,NULL);
	menu->setPosition(CCPointZero);
		
	this->addChild(menu,1,156);
	//暂停层
	PauseLayer* pauseLayer=PauseLayer::create();
	pauseLayer->setPosition(CCPointZero);
	pauseLayer->setVisible(false);
	this->addChild(pauseLayer,10,99);
	//创建飞机
	mWarrior=WarriorLayer::create();
	this->addChild(mWarrior);
	//创建子弹层
	bullet=BulletManage::create();
	this->addChild(bullet);
	this->schedule(schedule_selector(GameLayer::add_new_bullet),0.3f);
	Effects::sharedEffects()->preLoad();
	this->scheduleUpdate();
	enemy=EnemyLayer::create();
	this->addChild(enemy);
}
void GameLayer::update(float delta)
{
	CCArray* bulletsToDelete = CCArray::create();//创建一个CCArray，用以存放待删除的子弹，也就是此帧中被检测到碰撞的子弹
	bulletsToDelete->retain();//必须调用retain，CCArray内部调用了autoRelease
	CCObject* bt,*et;
	CCArray* enemyToDelete = CCArray::create();//创建一个CCArray，用以存放待删除的敌机，也就是此子弹击中的敌机
	enemyToDelete->retain();//调用retain

		//检测敌机和hero是否相撞
	CCARRAY_FOREACH(this->enemy->enemysArray,et)//遍历所有敌机
	{
		//CCSprite* enemy=(CCSprite*)et;
		Enemy* enemy=(Enemy*)et;	
		if(enemy->boundingBox().intersectsRect(this->mWarrior->m_warrrior->boundingBox())) 
		{
			//CCLOG("a");
			Effects::sharedEffects()->boom( this, this->mWarrior->m_warrrior->getPosition() );
			return;
		}
	}

	//检测敌机和子弹是否相撞
	CCARRAY_FOREACH(this->bullet->bulletsArray,bt)//遍历所有子弹    
	{    
		CCSprite* bullet = (CCSprite*)bt;

		CCARRAY_FOREACH(this->enemy->enemysArray,et)//遍历所有敌机
		{
			//CCSprite* enemy=(CCSprite*)et;
            Enemy* enemy=(Enemy*)et;

			if(enemy->boundingBox().intersectsRect(bullet->boundingBox())) 
			{
				int life=enemy->getLife();
				life--;
				if(0>=life)
				{
					enemyToDelete->addObject(enemy);//把待删除敌机放入CCArray
				}
				else
				{
					CCPoint p=enemy->getPosition();
					Effects::sharedEffects()->hit( this, ccp(p.x,p.y-10) );
					enemy->setLife(life);
				}
				bulletsToDelete->addObject(bullet);//把待删除子弹放入CCArray
				
			}
		}

	}

	CCARRAY_FOREACH(enemyToDelete,et)//遍历所有此帧中碰撞死亡的敌机，必须是死亡
	{
		//CCSprite* enemy3 = (CCSprite*)et;
		Enemy* enemy3=(Enemy*)et;
		Effects::sharedEffects()->boom( this, enemy3->getPosition() );
		if(CCRANDOM_0_1()<1)
		{
			CCSprite* sp=CCSprite::create("Icon-Small.png");
			sp->setPosition(enemy3->getPosition());
			this->addChild(sp);
			int time=enemy3->getPosition().y/100;
			CCMoveTo* move=CCMoveTo::create(time,ccp(enemy3->getPosition().x,0));

			CCActionInterval* rotate=CCRotateTo::create(1, 0.0f,180.0f);
			CCActionInterval* rotateBack=CCRotateTo::create(1, 0.0f,360.0f);
			//CCActionInstant* func =CCCallFuncN::create(this,callfuncN_selector(EnemyLayer::finishMoveCallback));
			//sp->runAction(CCSequence::create(move,NULL));
			CCRepeatForever* rf=CCRepeatForever::create(CCSequence::create(rotate,rotateBack,NULL));
			sp->runAction(rf);
			sp->runAction(move);
		}
		if(this->enemy->enemysArray->containsObject(enemy3))//防止已经删除了
			this->enemy->enemysArray->removeObject(enemy3);
		if(this->enemy->mEnemyBatchNode->getChildren()->containsObject(enemy3))
			this->enemy->mEnemyBatchNode->removeChild(enemy3,true);
	}
	enemyToDelete->release();//release

	CCARRAY_FOREACH(bulletsToDelete,bt)//遍历所有此帧中碰撞的子弹
	{
		CCSprite* bullet = (CCSprite*)bt;
		if(this->bullet->bulletsArray->containsObject(bullet))
			this->bullet->bulletsArray->removeObject(bullet);
		if(this->bullet->mBulletsBatchNode->getChildren()->containsObject(bullet))
			this->bullet->mBulletsBatchNode->removeChild(bullet,true);
	}
	bulletsToDelete->release();//release
}
void GameLayer::add_new_bullet(float t)
{
	bullet->addNewBullet(mWarrior->getHeroPosition(),mWarrior->getHeroSize());
}
void GameLayer::pause_logic(CCObject *psender)
{
	getChildByTag(99)->setVisible(true);
	CCDirector::sharedDirector()->pause();
	CCMenu* menu=(CCMenu*)getChildByTag(156);
	menu->setVisible(false);
}
//background滚动逻辑的回调方法
void GameLayer::background_scroll_logic(float t)
{
	CCSprite* bg1=(CCSprite*)getChildByTag(11);
	CCSprite* bg2=(CCSprite*)getChildByTag(12);

	bg1->setPositionY(bg1->getPositionY()-2);
	bg2->setPositionY(bg1->getPositionY()+576);
	if(bg2->getPositionY()<=0)
	{
		bg1->setPositionY(0);
	}
}
//获取场景指针
CCScene* GameLayer::scene()
{
	CCScene* sc=NULL;
	do
	{
		sc = CCScene::create();
		CC_BREAK_IF(!sc);
		GameLayer * layer=GameLayer::create();

		CC_BREAK_IF(!layer);

		sc->addChild(layer);
	}
	while(0);
	return sc;
}
 