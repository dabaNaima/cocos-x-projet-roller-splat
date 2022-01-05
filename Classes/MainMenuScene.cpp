#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "appDelegate.h"
#include "level1.h"

USING_NS_CC;


Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();
}


bool MainMenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("bac.png");


	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	background->setScale(4.2);
	this->addChild(background, 0);

	//on ajoute 
	auto label = Label::createWithTTF(" welcome to rollerSplat world let's play  ", "fonts/Marker Felt.ttf", 24);

	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}


	//auto title = Sprite::create("title.png");
	//title->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - title->getContentSize( ).height));
	//this->addChild(title, 1);


	auto play = MenuItemFont::create("start", CC_CALLBACK_1(MainMenuScene::GoToLevel1, this));
	auto menu = Menu::create(play, NULL);
	menu->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(menu, 1);




	return true;
}
void MainMenuScene::GoToLevel1(cocos2d::Ref* sender) {
	auto scene = level1::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(transition_time, scene));

}