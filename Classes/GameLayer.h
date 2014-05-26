#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#include "BasicLayer.h"
#include "BulletManage.h"
#include "WarriorLayer.h"
#include "EnemyLayer.h"
#include "ScoreLayer.h"
#include "DoubleLayer.h"
USING_NS_CC;
class GameLayer : public BasicLayer
{
public:
	GameLayer();
	~GameLayer();
    
    virtual bool init();
    static CCScene* scene();    
    void setupViews();
	void pause_logic(CCObject *psender);
	void background_scroll_logic(float t);
	EnemyLayer* enemy;
	void add_new_bullet(float t);
    CREATE_FUNC(GameLayer);
	virtual void update(float delta);
	CC_SYNTHESIZE(ScoreLayer*, scoreLayer, ScroeLayer);
private:
	WarriorLayer* mWarrior;
	BulletManage* bullet;
	DoubleLayer* mDoubleLayer;
	int times;
};

#endif // __GAMELAYER_H__