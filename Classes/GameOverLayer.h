#ifndef __GAMEOVERLAYER_H__
#define __GAMEOVERLAYER_H__

#include "BasicLayer.h"
USING_NS_CC;
class GameOverLayer : public BasicLayer
{
public:
	GameOverLayer();
	~GameOverLayer();
    
    virtual bool init();
	static CCScene* scene(int score);   
    void setupViews();
	void back_callback(CCObject *pSender);
	void play_again_callback(CCObject *pSender);
	void setScore(int score);
    CREATE_FUNC(GameOverLayer);
	//static GameOverLayer* create() ;
	int m_score;
};

#endif // __GAMEOVERLAYER_H__