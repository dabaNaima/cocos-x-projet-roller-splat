
#ifndef _LEVEL2_SCENE_H_
#define _LEVEL2_SCENE_H_

#include "cocos2d.h"

class level2 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(level2);
    //on ajoute ce variable privé


    cocos2d::DrawNode* drawNode;
private:
    void GoToLevel3Scene(cocos2d::Ref* sender);
};

#endif // _HELLOWORLD_SCENE_H_