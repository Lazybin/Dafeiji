#include "DoubleLayer.h"
bool DoubleLayer::init()
{
	bool bRet=false;
	do
	{
		CC_BREAK_IF(!BasicLayer::init());
		setupViews();
		bRet=true;
	}while(0);
	return bRet;
}
void DoubleLayer::setupViews()
{
	mDoubleBatchNode = CCSpriteBatchNode::create( "Icon-Small.png" );
	this->addChild(mDoubleBatchNode );
        
    //  4.初始化数组
    doubleArray = CCArray::create();
    doubleArray->retain();
}
void DoubleLayer::addDouble(CCPoint point)
{
	CCSprite* sp=CCSprite::create("Icon-Small.png");
	sp->setPosition(point);
	int time=point.y/100;
	CCMoveTo* move=CCMoveTo::create(time,ccp(point.x,0));

	CCActionInterval* rotate=CCRotateTo::create(1, 0.0f,180.0f);
	CCActionInterval* rotateBack=CCRotateTo::create(1, 0.0f,360.0f);
	//CCActionInstant* func =CCCallFuncN::create(this,callfuncN_selector(EnemyLayer::finishMoveCallback));
	//sp->runAction(CCSequence::create(move,NULL));
	CCRepeatForever* rf=CCRepeatForever::create(CCSequence::create(rotate,rotateBack,NULL));

	mDoubleBatchNode->addChild(sp);
	doubleArray->addObject(sp);
	sp->runAction(rf);
	CCActionInstant* func =CCCallFuncN::create(this,callfuncN_selector(DoubleLayer::finishMoveCallback));
	sp->runAction(CCSequence::create(move,func,NULL));
}
//bool DoubleSprite::init(char* fileName)
//{
//	bool bRet = false;
//    do 
//    {
//		CC_BREAK_IF(!CCSprite::initWithFile(fileName));
//        bRet = true;
//
//    } while (0);
//
//    return bRet;
//}
//DoubleSprite* DoubleSprite::create(char* fileName)
//{
//	DoubleSprite* pRet =new DoubleSprite();
//	if (pRet && pRet->init(fileName))
//    { 
//        pRet->autorelease(); 
//        return pRet; 
//    } 
//    else 
//    { 
//        delete pRet; 
//        pRet = NULL; 
//        return NULL; 
//    }
//}
//void DoubleSprite::executeAction(CCPoint p)
//{
//		int time=p.y/100;
//		CCMoveTo* move=CCMoveTo::create(time,ccp(p.x,0));
//
//		CCActionInterval* rotate=CCRotateTo::create(1, 0.0f,180.0f);
//		CCActionInterval* rotateBack=CCRotateTo::create(1, 0.0f,360.0f);
//		//CCActionInstant* func =CCCallFuncN::create(this,callfuncN_selector(EnemyLayer::finishMoveCallback));
//		//sp->runAction(CCSequence::create(move,NULL));
//		CCRepeatForever* rf=CCRepeatForever::create(CCSequence::create(rotate,rotateBack,NULL));
//		this->runAction(rf);
//		CCActionInstant* func =CCCallFuncN::create(this,callfuncN_selector(DoubleSprite::finishMoveCallback));
//		this->runAction(CCSequence::create(move,func,NULL));
//}
void  DoubleLayer::finishMoveCallback(CCNode *pSender)
{
	if(pSender!=NULL)
	{
		CCSprite* sp=(CCSprite*)pSender;
		if(mDoubleBatchNode->getChildren()->containsObject((CCObject*)sp))
		{
			mDoubleBatchNode->removeChild(sp,true);
		}
		if(doubleArray->containsObject(sp))
		{
			doubleArray->removeObject(sp);
		}
	}
}