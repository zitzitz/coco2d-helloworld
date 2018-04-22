#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "cocos2d.h"


class MainMenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(MainMenuScene);
private:
    void menuGoGameScene(cocos2d::Ref* pSender);
    void menuQuite(cocos2d::Ref* pSender);
};

#endif // MAINMENUSCENE_H
