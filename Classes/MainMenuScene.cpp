#include "MainMenuScene.h"
#include "Define.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    auto scene = Scene::create();

    auto layer = MainMenuScene::create();

    scene->addChild(layer);

    return scene;
}

bool MainMenuScene::init()
{
    if(!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bg = cocos2d::LayerColor::create(Color4B(53, 53, 53, 255));
    this->addChild(bg);


    auto playButton = MenuItemImage::create(
                                            "PlayButton.png",
                                            "PlayButtonClicked.png",
                                            CC_CALLBACK_1(MainMenuScene::menuGoGameScene, this)
                                            );
    auto quitButton = MenuItemImage::create(
                                            "quiteButton.png",
                                            "quiteButtonClicked.png",
                                            CC_CALLBACK_1(MainMenuScene::menuQuite, this)
                                            );

    auto menu = Menu::create(playButton, quitButton, NULL);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(menu);


    return true;
}

void MainMenuScene::menuGoGameScene(Ref *pSender)
{
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, GameScene::createScene() ) );
}

void MainMenuScene::menuQuite(Ref *pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
