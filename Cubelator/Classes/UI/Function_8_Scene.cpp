//
//  Function_8_Scene.cpp
//  Cubelator
//
//  Created by 张大方 on 2018/11/23.
//

#include "Function_8_Scene.hpp"
#include "Vector1.h"

Scene* Func_8_Scene::createScene(){
    return Func_8_Scene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool Func_8_Scene::init(){
    if ( !Scene::init() )
    {
        return false;
    }
    
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    this->Result->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-30));
    this->addChild(Result,5);
    this->Result->setColor(Color3B(0, 0, 0));
    
    
    //Load Background pic
    auto backGroundSprite  = Sprite::create("BackGround2.png");
    backGroundSprite->setPosition(origin.x + visibleSize.width/2 ,origin.y+ visibleSize.height/2 );
    auto bg_size = backGroundSprite->getContentSize();
    backGroundSprite->setScaleY(visibleSize.height/bg_size.height);
    backGroundSprite->setScaleX(visibleSize.width/bg_size.width);
    this->addChild(backGroundSprite, -1);
    
    auto MenuItem1 = MenuItemFont::create("8.四则运算表达式求值");
    MenuItem1->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem1->setColor(Color3B(0, 0, 0));
    MenuItem1->setPosition(Vec2( visibleSize.width/2,visibleSize.height-MenuItem1->getContentSize().height+30));
    
    /*
     this->Arith->setString("Result");
     this->Arith->setColor(Color3B(55, 55, 55));
     this->Arith->setFontNameObj("fonts/STHeiti Medium.ttc");
     this->Arith->setPosition(visibleSize/2);
     */
    
    
    
    
    
    auto BackButton = MenuItemImage::create("back_128.png", "back_128.png", CC_CALLBACK_1(Func_8_Scene::menuBackCallback, this));
    BackButton->setScale(0.5);
    BackButton->setAnchorPoint(Vec2::ZERO);
    BackButton->setPosition(20,visibleSize.height/2);
    
    
    
    
    auto textField = TextField::create("Input Here", "Arial", 20);
    textField->setPosition(Vec2(visibleSize.width/2,visibleSize.height-3*textField->getContentSize().height ));
    textField->setTextColor(Color4B(Color3B(55, 55, 55)));
    this->addChild(textField,3);
    textField->addEventListener(CC_CALLBACK_2(Func_8_Scene::textFirldEvent, this));
    textField->setCursorEnabled(true);
    
    
    //Init Compute Button
    auto ComputeButton = MenuItemImage::create("Calcu1.png","Calcu2.png",CC_CALLBACK_1(Func_8_Scene::Compute, this));
    ComputeButton->setAnchorPoint(Vec2::ZERO);
    ComputeButton->setPosition(Vec2(visibleSize.width-ComputeButton->getContentSize().width-10,ComputeButton->getContentSize().height));
    
    
    auto menu = Menu::create(MenuItem1,BackButton,ComputeButton,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
    
    return true;
    
    
}

void Func_8_Scene::menuBackCallback(Ref* pSender){
    Director::getInstance()->popScene();
}
void Func_8_Scene::Compute(Ref *pSender){
    if(this->Instruction.length()){
    auto ari = Arithmetic(this->Instruction);
    cout << "The result is : " << ari.getResult() << endl;
    string tmp = to_string(ari.getResult());
    this->Result->setString(to_string(ari.getResult()));
    }
}
void Func_8_Scene:: textFirldEvent(Ref * sender, TextField::EventType type){
    TextField *textField = dynamic_cast<TextField *>(sender);
    
    switch (type) {
            
        case TextField::EventType::ATTACH_WITH_IME :
            log("Start typing");
            break;
        case TextField::EventType::DETACH_WITH_IME :
            log("End typing");
            break;
        case TextField::EventType::INSERT_TEXT :
            textField->setString(textField->getString());
            this->Instruction = textField->getString();
            
            log("%s",textField->getString().c_str());
            break;
        case TextField::EventType::DELETE_BACKWARD :
            this->Instruction = textField->getString();
            log("%s",textField->getString().c_str());
            log("Arithmetic: %s",this->Instruction.c_str());
            break;
        default:
            break;
    }
}
