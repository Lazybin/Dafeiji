#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "cocos2d.h"
#include "BasicLayer.h"
USING_NS_CC;
enum planeType {enemy0, enemy1, enemy2,enemy3,enemy4,enemy5};
class Enemy:public CCSprite
{
public:
	CC_SYNTHESIZE(float, m_speed, Speed);
    CC_SYNTHESIZE(int, m_life, Life);
    CC_SYNTHESIZE(int, m_score, Score);
    //CC_SYNTHESIZE(planeType, m_type, Type);
	virtual bool init(planeType type);
	static Enemy* createWithSpriteFrameName(planeType type);
};
#endif // __ENEMY_H__