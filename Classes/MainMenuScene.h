
#ifndef _MainMenuScene_SCENE_H_
#define _MainMenuScene_SCENE_H_

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

private:
    void GoToLevel1(cocos2d::Ref* sender);



    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);
};

#endif // _MainMenuScene_SCENE_H_