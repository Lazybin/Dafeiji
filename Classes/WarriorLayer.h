#ifndef __WARRRIORLAYER_H__
#define __WARRRIORLAYER_H__

#include "BasicLayer.h"
USING_NS_CC;
class WarriorLayer : public BasicLayer
{
public:
	WarriorLayer();
	~WarriorLayer();
    
    virtual bool init();
    static CCScene* scene();    
    void setupViews();
    CREATE_FUNC(WarriorLayer);
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	//virtual void onEnter();
	virtual void registerWithTouchDispatcher(void);
	CCPoint getHeroPosition();
	CCSize getHeroSize();
	CCSprite* m_warrrior;
	CCPoint touchBeganPosition;
	CCPoint heroBeganPosition;
};

#endif // __WARRRIORLAYER_H__