//
//  FunctionMenuScene.hpp
//  Cubelator
//
//  Created by 张大方 on 2018/11/16.
//

#ifndef FunctionMenuScene_hpp
#define FunctionMenuScene_hpp

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"
using namespace std;

class FunctionMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(FunctionMenu);
    
private:
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void Function1Callback(cocos2d::Ref* pSender);
    void Function2Callback(cocos2d::Ref* pSender);
    void Function3Callback(cocos2d::Ref* pSender);
    void Function4Callback(cocos2d::Ref* pSender);
    void Function5Callback(cocos2d::Ref* pSender);
    void Function6Callback(cocos2d::Ref* pSender);
    void Function7Callback(cocos2d::Ref* pSender);
    void Function8Callback(cocos2d::Ref* pSender);
    void Function9Callback(cocos2d::Ref* pSender);
};
#endif /* FunctionMenuScene_hpp */
