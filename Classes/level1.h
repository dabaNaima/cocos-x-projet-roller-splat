
#ifndef _level1_SCENE_H_
#define _level1_SCENE_H_


#include "cocos2d.h"

class level1 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(level1);

    cocos2d::DrawNode* drawNode;
    //on ajoute ce variable privé
private:
    void GoToLevel2Scene(cocos2d::Ref* sender);
};

#endif // _HELLOWORLD_SCENE_H_