#include "BulletManage.h"
#include "EnemyLayer.h"
#include "GameLayer.h"
#include "Effects.h"
BulletManage::BulletManage()
{
	//子弹飞行速度;
	speed=320;
}
BulletManage::~BulletManage(){}
    
bool BulletManage::init()
{
	if(!BasicLayer::init())
		return false;
	setupViews();
	return true;
}
void BulletManage:: setupViews()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist", "bullet.png" );
        
        
        //  2.读取其中英雄的子弹然后加入到CCSpriteBatchNode中
        
        mBulletsBatchNode = CCSpriteBatchNode::create( "bullet.png" );
         
        //  3.为CCSpritBatchNode 加入光晕效果
        ccBlendFunc cb = {GL_SRC_ALPHA, GL_ONE };
        
        mBulletsBatchNode->setBlendFunc( cb );
        
        this->addChild(mBulletsBatchNode );
        
        //  4.初始化数组
        bulletsArray = CCArray::create();
        bulletsArray->retain();

		 //  5.预加载特效类 和 爆炸动画
        //Effects::sharedEffects()->preLoad();
      

}

//  添加子弹 -- 对外的 其实就是对WarriorLayer
void BulletManage::addNewBullet(const CCPoint point,const CCSize heroSize)
{
	
    //  飞机的左子弹
	CCSprite* bulletsLeft=CCSprite::createWithSpriteFrameName("W1.png");
    bulletsLeft->setPosition(ccp(point.x-20,point.y+10));
	float moveTime=(getWinSize().height-point.y+10)/speed;
	//结束位置
	CCPoint endLeft=ccp(point.x-20,getWinSize().height);

    //  飞机的右子弹
    CCSprite* bulletsRight=CCSprite::createWithSpriteFrameName("W1.png");
    bulletsRight->setPosition(ccp(point.x+20,point.y+10));
    
	CCPoint endRight=ccp(point.x+20,getWinSize().height);
    //  飞机的中间子弹
    
    
    //  加入到数组中
	bulletsArray->addObject(bulletsLeft);
    bulletsArray->addObject(bulletsRight);
    //  加入到BatchNode中
    mBulletsBatchNode->addChild(bulletsLeft);
	mBulletsBatchNode->addChild(bulletsRight);

	CCMoveTo* moveToLeft = CCMoveTo::create(moveTime,endLeft);
	CCMoveTo* moveToRight = CCMoveTo::create(moveTime,endRight);

	CCActionInstant* func=CCCallFuncN::create(this,callfuncN_selector(BulletManage::removeBullet));
    bulletsLeft->runAction( CCSequence::create( moveToLeft,func,NULL) );
	bulletsRight->runAction(CCSequence::create( moveToRight,func,NULL) );

}
void BulletManage::removeBullet(CCNode* pSender)
{
	if(pSender!=NULL)
	{
		CCSprite* sp=(CCSprite*)pSender;
		if(mBulletsBatchNode->getChildren()->containsObject((CCObject*)sp))
		{
			mBulletsBatchNode->removeChild(sp,true);
		}
		if(bulletsArray->containsObject(sp))
		{
			bulletsArray->removeObject(sp);
		}
	}
}
void BulletManage::moveAllBullets(float t)
{
	//CCSize size = getWinSize();
	//CCObject *obj=NULL;
	//CCObject *oo=NULL;
	//CCARRAY_FOREACH(bulletsArray,obj)
	//{
	//	CCSprite* sp=(CCSprite*)obj;
	//	sp->setPositionY(sp->getPositionY()+10);
	//	if(sp->getPositionY()>size.height)
	//	{
	//		mBulletsBatchNode->removeChild(sp,true);
	//		bulletsArray->removeObject(sp);
	//		continue;
	//	}
	//	GameLayer* gameLayer=(GameLayer*)this->getParent();
	//	CCArray* enemys=gameLayer->enemy->enemysArray;
	//	CCSpriteBatchNode* mEnemyBatchNode=gameLayer->enemy->mEnemyBatchNode;
	//	//CCLOG("%f,%f",sp->getPositionX(),sp->getPositionY());
	//	CCARRAY_FOREACH(enemys,obj)
	//	{
	//		Enemy* e=(Enemy*)obj;
	//		//CCLOG("%f",e->enemy->getPositionX());
	//		if(sp->boundingBox().intersectsRect(e->enemy->boundingBox()))
	//		{
	//			//移除子弹
	//			
	//			Effects::sharedEffects()->boom( this->getParent(), e->enemy->getPosition() );
	//			CCLOG("boom!");
	//			enemys->removeObject(e);
	//			mEnemyBatchNode->removeChild(e->enemy,true);
	//			mBulletsBatchNode->removeChild(sp,true);
	//	        bulletsArray->removeObject(sp);
	//			break;
	//		}
	//		
	//	}
	//	
	//}
}