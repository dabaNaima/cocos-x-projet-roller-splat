#include "level1.h"
#include "SimpleAudioEngine.h"
#include "appDelegate.h"
#include "MainMenuScene.h"
#include "Level2Scene.h"

USING_NS_CC;

Scene* level1::createScene()
{
    return level1::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool level1::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   
    
    
    //add audio 

    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("music-balon.wav");


    auto label = Label::createWithTTF("level 1 ", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("level1111.png");
    if (sprite == nullptr)
    {
        problemLoading("'level1111.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    auto balsprite = Sprite::create("ballon.png");
    if (sprite == nullptr)
    {
        problemLoading("'ballon.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        balsprite->setPosition(Vec2(120, 90));

        // add the sprite as a child to this layer
        this->addChild(balsprite, 1);

        drawNode = DrawNode::create();
        drawNode->drawPoint(Vec2(120, 90), 75.0f, Color4F::BLUE);
        this->addChild(drawNode);
        //code for us Handling Keyboard Events


        auto eventListener = EventListenerKeyboard::create();



        eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

            Vec2 loc = event->getCurrentTarget()->getPosition();
            switch (keyCode) {
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                //event->getCurrentTarget()->setPosition(loc.x-=20, loc.y);
                if (loc.x == 450 && loc.y == 328) {
                    event->getCurrentTarget()->setPosition(loc.x -= 330, loc.y);

                    auto scene = level2::createScene();
                    Director::getInstance()->replaceScene(TransitionFade::create(transition_time, scene));
              
                    CocosDenshion::SimpleAudioEngine::getInstance()->
                        playEffect("music-balon.wav");
                }
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                //   event->getCurrentTarget()->setPosition(loc.x+=20, loc.y);
                if (loc.x == 120 && loc.y == 90) {
                    event->getCurrentTarget()->setPosition(loc.x += 330, loc.y);

                    CocosDenshion::SimpleAudioEngine::getInstance()->
                        playEffect("music-balon.wav");
                }

                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                // event->getCurrentTarget()->setPosition(loc.x, loc.y+=20);
                if (loc.x == 450 && loc.y == 90) {
                    event->getCurrentTarget()->setPosition(loc.x, loc.y += 238);

                    CocosDenshion::SimpleAudioEngine::getInstance()->
                        playEffect("music-balon.wav");
                }
                break;
               
            }
        };

        this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, balsprite);


      

        this->scheduleUpdate();
    }

    return true;
}


void level1::GoToLevel2Scene(cocos2d::Ref* sender) {
    auto scene = MainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(transition_time, scene));

    


}