//
//  Function_1_Scene.hpp
//  Cubelator
//
//  Created by 张大方 on 2018/11/19.
//

#ifndef Function_1_Scene_hpp
#define Function_1_Scene_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>

#include "Vector1.h"

#include "ui/CocosGUI.h"



USING_NS_CC;
using namespace std;
using namespace ui;


class Func_1_Scene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(Func_1_Scene);
    
    //Check "+" if is true, "-" if is false;
    bool AddOrMinus = true;
    
    
    int dimension;
    int x[100],y[100];
    string x_vector,y_vector;
    string Instruction;
    Text* Result = Text::create("Result", "Arial", 25);
    MenuItemImage* AddBox = MenuItemImage::create("plus1.png", "plus2.png");
    MenuItemImage* MinusBox = MenuItemImage::create("minus1.png", "minus2.png");
    
    MenuItemFont* Title = MenuItemFont::create("同维度向量的加法");
    
private:
    
    // a selector callback
    void menuBackCallback(cocos2d::Ref* pSender);
    void Compute(Ref* pSender);
    
    void textFieldEvent(Ref * sender, TextField::EventType type);
    void DimensionInputEvent(Ref * sender, TextField::EventType type);
    void Vector1_InputEvent(Ref * sender, TextField::EventType type);
    void Vector2_InputEvent(Ref * sender, TextField::EventType type);
    
    void string2vector(int* ,string vector);
    
    
    void switch2Add(Ref* sender);
    void switch2Minus(Ref* sender);
};



#endif /* Function_1_Scene_hpp */
