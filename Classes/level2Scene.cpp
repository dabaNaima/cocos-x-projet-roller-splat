#include "level2Scene.h"
#include "SimpleAudioEngine.h"
#include "appDelegate.h"
#include "Level3Scene.h"
USING_NS_CC;

Scene* level2::createScene()
{
    return level2::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}



// on "init" you need to initialize your instance


bool level2::init()
{

    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    //droweNode



    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    //add audio 
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("music-balon.wav");


    auto label = Label::createWithTTF("level 2 ", "fonts/Marker Felt.ttf", 24);
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
    auto sprite = Sprite::create("level2.png");
    if (sprite == nullptr)
    {
        problemLoading("'level2.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    auto balsprite = Sprite::create("ballon2.png");
    if (sprite == nullptr)
    {
        problemLoading("'ballon2.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        balsprite->setPosition(Vec2(120, 320));

        // add the sprite as a child to this layer
        this->addChild(balsprite, 1);



        drawNode = DrawNode::create();
        drawNode->drawPoint(Vec2(123, 312), 86.0f, Color4F::RED);
        this->addChild(drawNode);

        // add the sprite as a child to this layer

    //code for us Handling Keyboard Events


        auto eventListener = EventListenerKeyboard::create();



        eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

            Vec2 loc = event->getCurrentTarget()->getPosition();
            switch (keyCode) {
                // pour mettre la balle a gauche 
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:

                if (loc.x == 455 && loc.y == 320) {
                    event->getCurrentTarget()->setPosition(loc.x -= 170, loc.y);

                    auto scene = level3::createScene();
                    Director::getInstance()->replaceScene(TransitionFade::create(transition_time, scene));
               
                    CocosDenshion::SimpleAudioEngine::getInstance()->
                        playEffect("music-balon.wav");
                }
                break;
                // pour mettre la balle a droite 
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:

                if (loc.x == 120 && loc.y == 107) {
                    event->getCurrentTarget()->setPosition(loc.x += 335, loc.y);

                    CocosDenshion::SimpleAudioEngine::getInstance()->
                        playEffect("music-balon.wav");
                }

                break;

                // pour mettre la balle en haut
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                if (loc.x == 455 && loc.y == 107) {
                    event->getCurrentTarget()->setPosition(loc.x, loc.y += 213);
              
                    CocosDenshion::SimpleAudioEngine::getInstance()->
                        playEffect("music-balon.wav");
                }
                break;
                // pour ramener la balle vers la bas
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:

                if (loc.x == 120 && loc.y == 320) {
                    event->getCurrentTarget()->setPosition(loc.x, loc.y -= 213);
             
                    CocosDenshion::SimpleAudioEngine::getInstance()->
                        playEffect("music-balon.wav");
                }
                break;

            }

        };

        this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, balsprite);


        //auto moveTo = MoveTo::create(2, Vec2(450, 80));
        //auto playbutton = balsprite->runAction(moveTo);

        this->scheduleUpdate();
    }


    return true;
}


void level2::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    // To navigate back to native iOS screen(if present) without quitting the application, do not use Director::getInstance()->end() as given above, instead trigger a custom event created in RootViewController.mm as below /

        //EventCustom customEndEvent("game_scene_close_event");
        //_eventDispatcher->dispatchEvent(&customEndEvent);


}