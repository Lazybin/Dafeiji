#ifndef __SCORELAYER_H__
#define __SCORELAYER_H__

#include "BasicLayer.h"
USING_NS_CC;
class ScoreLayer : public BasicLayer
{
public:
	ScoreLayer();
	~ScoreLayer();
    CC_SYNTHESIZE(int, m_score, Scroe);
    virtual bool init();
    static CCScene* scene();    
    void setupViews();
    CREATE_FUNC(ScoreLayer);
	void updateScore(int score);
private:
	CCLabelBMFont* scoreFont;
};

#endif // __SCORELAYER_H__