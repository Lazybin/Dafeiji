//
//  Effects.h
//  MyMoonWarrior
//
//  Created by cesc on 13-4-14.
//
//

#ifndef __EFFECTS_H__
#define __EFFECTS_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Effects {
    
    
public:
    
    static Effects* sharedEffects();
    
    //   预加载动画到CCAnimationCache中
    void preLoad();
    
    void enemy_boom( CCNode* target, CCPoint point );
	void hero_boom( CCNode* target, CCPoint point );
	void hit( CCNode* target, CCPoint point );
    
    void boom_callback( CCNode* pNode );
    void hit_callback( CCNode* pNode );

};
#endif //__EFFECTS_H__
