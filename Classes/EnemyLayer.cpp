#include "EnemyLayer.h"
#include "Enemy.h"
EnemyLayer::EnemyLayer(){}
EnemyLayer::~EnemyLayer(){}
    
bool EnemyLayer::init()
{
	if(!BasicLayer::init())
		return false;
	setupViews();
	return true;
}
void EnemyLayer::setupViews()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Enemy.plist");
        
    mEnemyBatchNode = CCSpriteBatchNode::create( "Enemy.png" );
	
    this->addChild(mEnemyBatchNode );
        
    //  4.初始化数组
    enemysArray = CCArray::create();
    enemysArray->retain();
	//每隔多久生成敌机
	this->schedule(schedule_selector(EnemyLayer::addEnemy),0.5f);

}
//每隔多久生成敌机
void EnemyLayer::addEnemy(float t)
{
	if(CCRANDOM_0_1()>=0.25f)
	{
		//随机取得敌机
		int index=(int)10*CCRANDOM_0_1();
		CCLOG("%d",index);
		if(index>5)
			index=index-5;		
		planeType type;
		type=(planeType)index;
		//CCSprite *enemySprite=CCSprite::createWithSpriteFrameName(str);
		Enemy *enemySprite=Enemy::createWithSpriteFrameName(type);
		//enemySprite->setScale(1.5);
		//随机设置初始位置
		float posX=getWinSize().width*CCRANDOM_0_1();
		float enemyWidth=enemySprite->getContentSize().width;
		//防止飞机超过边界
		if(posX-enemyWidth/2<0)
		{
			posX=posX+enemyWidth/2;
		}
		else if(posX+enemyWidth/2>getWinSize().width)
		{
			posX=posX-enemyWidth/2;
		}
		CCPoint position=ccp(posX,getWinSize().height);
		enemySprite->setPosition(position);
	
		mEnemyBatchNode->addChild(enemySprite);
		enemysArray->addObject(enemySprite);
		//移动敌机
		float time=(getWinSize().height*1.0/enemySprite->getSpeed());
		CCMoveTo* move=CCMoveTo::create(time,ccp(position.x,0));
		CCActionInstant* func =CCCallFuncN::create(this,callfuncN_selector(EnemyLayer::finishMoveCallback));
		enemySprite->runAction(CCSequence::create(move,func,NULL));
		
	}
}
void  EnemyLayer::finishMoveCallback(CCNode *pSender)
{
	if(pSender!=NULL)
	{
		CCSprite* sp=(CCSprite*)pSender;
		if(mEnemyBatchNode->getChildren()->containsObject((CCObject*)sp))
		{
			mEnemyBatchNode->removeChild(sp,true);
		}
		if(enemysArray->containsObject(sp))
		{
			enemysArray->removeObject(sp);
		}
	}
}

//敌机子弹
void EnemyLayer::moveAllEnemyBullet(float t)
{}