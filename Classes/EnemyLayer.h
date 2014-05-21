#ifndef __ENEMYLAYER_H__
#define __ENEMYLAYER_H__

#include "BasicLayer.h"

class EnemyLayer : public BasicLayer
{
public:
	EnemyLayer();
	~EnemyLayer();
    
    virtual bool init();
    void setupViews();
	//���ɵл�
	void addEnemy(float t);
	//�л��ӵ�
	void moveAllEnemyBullet(float t);
	void  finishMoveCallback(CCNode *pSender);
    CREATE_FUNC(EnemyLayer);
	CCArray* enemysArray;
	CCSpriteBatchNode* mEnemyBatchNode;
	
};

#endif // __ENEMYLAYER_H__