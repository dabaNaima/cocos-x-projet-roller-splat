
#ifndef _FIRST_SCENE_H_
#define _FIRST_SCENE_H_

#include "cocos2d.h"

class firstScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();


private:
    void GoToMainMenuScene(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(firstScene);
};

#endif // _firstScene_SCENE_H_
