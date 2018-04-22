#ifndef SPLASHSCREENSCENE_H
#define SPLASHSCREENSCENE_H

#include "cocos2d.h"


class SplashScreenScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(SplashScreenScene);
private:
    void GotoMenuScene(float);
};

#endif // SPLASHSCREENSCENE_H
