//
//  Function_8_Scene.hpp
//  Cubelator
//
//  Created by 张大方 on 2018/11/23.
//

#ifndef Function_8_Scene_hpp
#define Function_8_Scene_hpp


#include <stdio.h>
#include <string>
#include <iostream>


#include "ui/CocosGUI.h"
#include "ArithmeticX.h"
#include "Arithmetic.h"
#include "Vector1.h"

USING_NS_CC;
using namespace std;
using namespace ui;


class Func_8_Scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    MenuItemFont* Arith;
    // implement the "static create()" method manually
    CREATE_FUNC(Func_8_Scene);
    string Instruction;
    Text* Result = Text::create("Result", "Arial", 25);
    
    void textFirldEvent(Ref * sender, TextField::EventType type);
private:
    
    // a selector callback
    void menuBackCallback(cocos2d::Ref* pSender);
    void Compute(Ref* pSender);
};
#endif /* Function_8_Scene_hpp */
