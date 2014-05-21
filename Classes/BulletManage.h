#ifndef __BULLETMANAGE_H__
#define __BULLETMANAGE_H__

#include "BasicLayer.h"
USING_NS_CC;
class BulletManage : public BasicLayer
{
public:
	BulletManage();
	~BulletManage();
    
    virtual bool init(); 
    void setupViews();
	void addNewBullet(const CCPoint point, CCSize heroSize);
	void moveAllBullets(float t);
	void removeBullet(CCNode* pSender);
    CREATE_FUNC(BulletManage);
	CCSpriteBatchNode * mBulletsBatchNode;
	CCArray* bulletsArray;
	float speed;
};

#endif // __BULLETMANAGE_H__