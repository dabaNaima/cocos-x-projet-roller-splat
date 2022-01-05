#include "level3Scene.h"
#include "SimpleAudioEngine.h"
#include "appDelegate.h"
#include "Level4Scene.h"

USING_NS_CC;

Scene* level3::createScene()
{
    return level3::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool level3::init()
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

    auto label = Label::createWithTTF(" level 3 ", "fonts/Marker Felt.ttf", 24);

    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);


    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("level3.png");
    if (sprite == nullptr)
    {
        problemLoading("'level3.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));


        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    auto balsprite = Sprite::create("ballon3.png");

    problemLoading("'ballon3.png'");

    // position the sprite on the center of the screen
    balsprite->setPosition(Vec2(112, 335));

    // add the sprite as a child to this layer
    this->addChild(balsprite, 1);


    drawNode = DrawNode::create();
    drawNode->drawPoint(Vec2(109, 336), 59.0f, Color4F::YELLOW);
    this->addChild(drawNode);
    //  code for us Handling Keyboard Events and with a position of our bal we control her next  position  
    auto eventListener = EventListenerKeyboard::create();



    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            // pour mettre la balle vers la gauche 
            if (loc.x == 462 && loc.y == 85) {
                event->getCurrentTarget()->setPosition(loc.x -= 180, loc.y);
            
                CocosDenshion::SimpleAudioEngine::getInstance()->
                    playEffect("music-balon.wav");
            }
            if (loc.x == 292 && loc.y == 207) {
                event->getCurrentTarget()->setPosition(loc.x -= 170, loc.y);
           
                CocosDenshion::SimpleAudioEngine::getInstance()->
                    playEffect("music-balon.wav");
            }
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            //  pour mettre la balle a droite 
            if (loc.x == 112 && loc.y == 335) {
                event->getCurrentTarget()->setPosition(loc.x += 350, loc.y);

                CocosDenshion::SimpleAudioEngine::getInstance()->
                    playEffect("music-balon.wav");
            }

            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            // pour mettre la balle vers le haut  
            if (loc.x == 282 && loc.y == 85) {
                event->getCurrentTarget()->setPosition(loc.x += 10, loc.y += 122);
           
                CocosDenshion::SimpleAudioEngine::getInstance()->
                    playEffect("music-balon.wav");
            }
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            // pour mettre la balle en bas 
            if (loc.x == 462 && loc.y == 335) {
                event->getCurrentTarget()->setPosition(loc.x, loc.y -= 250);
          
                CocosDenshion::SimpleAudioEngine::getInstance()->
                    playEffect("music-balon.wav");
            }
            if (loc.x == 122 && loc.y == 207) {
                event->getCurrentTarget()->setPosition(loc.x, loc.y -= 121);

                auto scene = level4::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(transition_time, scene));
            
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

    return true;
}

void level3::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    // To navigate back to native iOS screen(if present) without quitting the application, do not use Director::getInstance()->end() as given above, instead trigger a custom event created in RootViewController.mm as below /

        //EventCustom customEndEvent("game_scene_close_event");
        //_eventDispatcher->dispatchEvent(&customEndEvent);


}
