#ifndef __WELCOMELAYER_H__
#define __WELCOMELAYER_H__

#include "BasicLayer.h"
USING_NS_CC;
class WelcomeLayer : public BasicLayer
{
public:
	WelcomeLayer();
	~WelcomeLayer();
    
    virtual bool init();

    static CCScene* scene();    
    void setupViews();
	void startgame_call_back(CCObject *pSender);
	void option_call_back(CCObject *pSender);
	virtual void onEnter();
    CREATE_FUNC(WelcomeLayer);
};

#endif // __WELCOMELAYER_H__