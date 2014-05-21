#include "BulletManage.h"
#include "EnemyLayer.h"
#include "GameLayer.h"
#include "Effects.h"
BulletManage::BulletManage()
{
	//�ӵ������ٶ�;
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
        
        
        //  2.��ȡ����Ӣ�۵��ӵ�Ȼ����뵽CCSpriteBatchNode��
        
        mBulletsBatchNode = CCSpriteBatchNode::create( "bullet.png" );
         
        //  3.ΪCCSpritBatchNode �������Ч��
        ccBlendFunc cb = {GL_SRC_ALPHA, GL_ONE };
        
        mBulletsBatchNode->setBlendFunc( cb );
        
        this->addChild(mBulletsBatchNode );
        
        //  4.��ʼ������
        bulletsArray = CCArray::create();
        bulletsArray->retain();

		 //  5.Ԥ������Ч�� �� ��ը����
        //Effects::sharedEffects()->preLoad();
      

}

//  ����ӵ� -- ����� ��ʵ���Ƕ�WarriorLayer
void BulletManage::addNewBullet(const CCPoint point,const CCSize heroSize)
{
	
    //  �ɻ������ӵ�
	CCSprite* bulletsLeft=CCSprite::createWithSpriteFrameName("W1.png");
    bulletsLeft->setPosition(ccp(point.x-20,point.y+10));
	float moveTime=(getWinSize().height-point.y+10)/speed;
	//����λ��
	CCPoint endLeft=ccp(point.x-20,getWinSize().height);

    //  �ɻ������ӵ�
    CCSprite* bulletsRight=CCSprite::createWithSpriteFrameName("W1.png");
    bulletsRight->setPosition(ccp(point.x+20,point.y+10));
    
	CCPoint endRight=ccp(point.x+20,getWinSize().height);
    //  �ɻ����м��ӵ�
    
    
    //  ���뵽������
	bulletsArray->addObject(bulletsLeft);
    bulletsArray->addObject(bulletsRight);
    //  ���뵽BatchNode��
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
	//			//�Ƴ��ӵ�
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