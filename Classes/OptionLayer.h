#ifndef __OPTIONLAYER_H__
#define __OPTIONLAYER_H__

#include "BasicLayer.h"
USING_NS_CC;
class OptionLayer : public BasicLayer
{
public:
	OptionLayer();
	~OptionLayer();
    
    virtual bool init();
	bool music_status;
    static CCScene* scene();    
    void setupViews();
	void setmusic_call_back(CCObject *pSender);
	void back_callback(CCObject *pSender);
    CREATE_FUNC(OptionLayer);
};

#endif // __OPTIONLAYER_H__