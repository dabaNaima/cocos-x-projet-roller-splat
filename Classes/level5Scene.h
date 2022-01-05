
#ifndef _LEVEL5_SCENE_H_
#define _LEVEL5_SCENE_H_

#include "cocos2d.h"

class level5 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(level5);
    cocos2d::DrawNode* drawNode;
};

#endif // _HELLOWORLD_SCENE_H_
