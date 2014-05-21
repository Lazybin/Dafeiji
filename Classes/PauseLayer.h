#ifndef __PAUSELAYER_H__
#define __PAUSELAYER_H__

#include "BasicLayer.h"
USING_NS_CC;
class PauseLayer : public CCLayerColor
{
public:
	PauseLayer();
	~PauseLayer();
    
    virtual bool init();
    static CCScene* scene();    
    void setupViews();
	void play_logic(CCObject* pSender);
    CREATE_FUNC(PauseLayer);
};

#endif // __PAUSELAYER_H__