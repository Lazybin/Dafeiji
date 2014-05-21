#include "Effects.h"

static Effects* instance = NULL;

Effects* Effects::sharedEffects(){

    if( !instance ){
    
        instance = new Effects();
    }
    
    
    return instance;
}

//   Ԥ���ض�����CCAnimationCache��
void Effects::preLoad(){
    
    //  ����ը��plist �� ͼƬ���뵽cache��
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "explosion.plist" );
    
    //  ����һ��CCAnimation
    CCAnimation* boomAnimation = CCAnimation::create();
    boomAnimation->setDelayPerUnit( 0.05f );
    boomAnimation->setLoops( 1 );
    
      //  ��plist �е�����ͼƬ���뵽CCAnimation��
    for (int i = 1; i <= 10; i++ ) {
         //for (i; i <= 2; i++ ) {
        char str[20] = {0};
        
        sprintf(str, "explosion_%02d.png",i );
		CCLOG(str);
        
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( str );
        
        boomAnimation->addSpriteFrame( pFrame );
       
    }
    
    
    //  �����CCAnimation ָ����뵽CCAnimationCache��
    
    CCAnimationCache::sharedAnimationCache()->addAnimation(boomAnimation, "boom" );
    

}
//  ���е�Ч��
void Effects::hit( CCNode* target, CCPoint point ){
    
    CCSprite* sp = CCSprite::createWithSpriteFrameName( "explosion_01.png" );
    
    target->addChild( sp,10 );
    sp->setPosition( point );
    
	CCAnimation* boomAnimation = CCAnimation::create();
    boomAnimation->setDelayPerUnit( 0.05f );
    boomAnimation->setLoops( 1 );

	 
    for (int i = 1; i <= 3; i++ ) {
         //for (i; i <= 2; i++ ) {
        char str[20] = {0};
        
        sprintf(str, "explosion_%02d.png",i );
		CCLOG(str);
        
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( str );
        
        boomAnimation->addSpriteFrame( pFrame );
       
    }
   
    
    CCAnimate* anim = CCAnimate::create( boomAnimation );
    
    //  2.дһ��CCSequence �����ص�
    CCCallFuncN* callback = CCCallFuncN::create(sp, callfuncN_selector( Effects::boom_callback));
    
    CCAction* actions = CCSequence::create( anim,callback,NULL );
    
    sp->runAction( actions );
    
    
    
}

//  ��ը��Ч��
void Effects::boom( CCNode* target, CCPoint point ){
    
    CCSprite* sp = CCSprite::createWithSpriteFrameName( "explosion_01.png" );
    
    target->addChild( sp,10 );
    sp->setPosition( point );
    
    //  1.��CCanimationcache �ж�ȡ��ը��animation
    CCAnimation* boomAnimation = CCAnimationCache::sharedAnimationCache()->animationByName( "boom" );
    
    CCAnimate* anim = CCAnimate::create( boomAnimation );
    
    //  2.дһ��CCSequence �����ص�
    CCCallFuncN* callback = CCCallFuncN::create(sp, callfuncN_selector( Effects::boom_callback));
    
    CCAction* actions = CCSequence::create( anim,callback,NULL );
    
    sp->runAction( actions );
    
    
    
}

void Effects::boom_callback( CCNode* pNode ){

    pNode->removeFromParentAndCleanup( true );
}
