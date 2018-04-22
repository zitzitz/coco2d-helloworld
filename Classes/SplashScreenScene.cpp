#include "SplashScreenScene.h"
#include "MainMenuScene.h"
#include "Define.h"

USING_NS_CC;

Scene * SplashScreenScene::createScene()
{
    auto scene = Scene::create();

    auto layer = SplashScreenScene::create();

    scene->addChild(layer);

    return scene;
}


bool SplashScreenScene::init()
{
    if( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto loadingSprite = Sprite::create("splash.png");
    loadingSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(loadingSprite, 0);

    this->scheduleOnce( schedule_selector( SplashScreenScene::GotoMenuScene ), SPLASH_SCENE_TIME);
    return true;
}

void SplashScreenScene::GotoMenuScene(float dt)
{
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, MainMenuScene::createScene() ) );

}
