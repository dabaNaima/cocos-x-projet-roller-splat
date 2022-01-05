#include "firstScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"
#include "appDelegate.h"

USING_NS_CC;


Scene* firstScene::createScene()
{
	return firstScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool firstScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// add audio 

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("music-fist.wav");

	 
	auto backround = Sprite::create("roller-splat.png");
	backround->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	backround->setScale(2.5);
	this->addChild(backround, 0);

	// a  animation bals  
	auto ballsprite = Sprite::create("ballon.png");
	ballsprite->setPosition(Point(100, 150));
	this->addChild(ballsprite);
	auto action = MoveBy::create(5, Point(0, 100));
	ballsprite->runAction(EaseElasticInOut::create(action, 0.5));

	//add audio 
	

	CocosDenshion::SimpleAudioEngine::getInstance()->
		playEffect("music-fist.wav");



	auto ballsprite2 = Sprite::create("ballon.png");
	ballsprite2->setPosition(Point(500, 150));
	this->addChild(ballsprite2);
	auto action2 = MoveBy::create(5, Point(0, 100));
	ballsprite2->runAction(EaseElasticInOut::create(action2, 0.5));

	this->scheduleOnce(schedule_selector(firstScene::GoToMainMenuScene), begin_time);


	return true;
}

void firstScene::GoToMainMenuScene(float dt) {
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(transition_time, scene));
}