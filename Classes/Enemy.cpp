#include "Enemy.h"
bool Enemy::init(planeType type)
{
	bool bRet = false;
    do 
    {
        float score = 0;
        int life = 0;
        float speed = 0;
		const char* fileName;
		switch(type)
		{
			case enemy0 :
				fileName="E0.png";
				score=10;
				life =1;
				speed=250;
				break;
			case enemy1 :
				fileName="E1.png";
				score=20;
				life =2;
				speed=220;
				break;
			case enemy2 :
				fileName="E2.png";
				score=30;
				life =3;
				speed=200;
				break;
			case enemy3 :
				fileName="E3.png";
				score=40;
				life =3;
				speed=180;
				break;
			case enemy4 :
				fileName="E4.png";
				score=150;
				life =3;
				speed=50;
				break;
			case enemy5 :
				fileName="E5.png";
				score=100;
				life =4;
				speed=30;
				break;
			default:
				break;

		}

        
		CC_BREAK_IF(!CCSprite::initWithSpriteFrameName(fileName));
        this->m_score = score;
        this->m_life = life;
        this->m_speed = speed;
        bRet = true;

    } while (0);

    return bRet;
}
Enemy* Enemy::createWithSpriteFrameName(planeType type)
{
	Enemy* pRet =new Enemy();
	if (pRet && pRet->init(type))
    { 
        pRet->autorelease(); 
        return pRet; 
    } 
    else 
    { 
        delete pRet; 
        pRet = NULL; 
        return NULL; 
    }
}