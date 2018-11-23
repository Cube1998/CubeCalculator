//
//  FunctionMenuScene.cpp
//  Cubelator
//
//  Created by 张大方 on 2018/11/16.
//

#include "FunctionMenuScene.hpp"
#include "Function_1_Scene.hpp"
#include "Function_8_Scene.hpp"

USING_NS_CC;

Scene* FunctionMenu::createScene()
{
    return FunctionMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool FunctionMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto backGroundSprite  = Sprite::create("BackGround2.png");
    
    backGroundSprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    auto bg_size = backGroundSprite->getContentSize();
    
    backGroundSprite->setScaleY(visibleSize.height/bg_size.height);
    this->addChild(backGroundSprite, -1);
    
    auto BackButton = MenuItemImage::create("back_128.png", "back_128.png", CC_CALLBACK_1(FunctionMenu::menuCloseCallback, this));
    BackButton->setScale(0.5);
    BackButton->setAnchorPoint(Vec2::ZERO);
    BackButton->setPosition(20,visibleSize.height/2);
    
    
    
    auto MenuItem1 = MenuItemFont::create("1.同维度向量的加减法", CC_CALLBACK_1(FunctionMenu:: Function1Callback, this));
    MenuItem1->setScale(0.5);
    MenuItem1->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem1->setColor(Color3B(0, 0, 0));
    MenuItem1->setPosition(Vec2( visibleSize.width/2,visibleSize.height/10*9));
    
    
    auto MenuItem2 = MenuItemFont::create("2.一元多项式的加减法", CC_CALLBACK_1(FunctionMenu::Function2Callback, this));
    MenuItem2->setScale(0.5);
    MenuItem2->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem2->setColor(Color3B(0, 0, 0));
    MenuItem2->setPosition(Vec2( visibleSize.width/2 ,visibleSize.height/10*8));
    
    
    
    auto MenuItem3 = MenuItemFont::create("3.向量的夹角余弦值", CC_CALLBACK_1(FunctionMenu:: Function3Callback, this));
    MenuItem3->setScale(0.5);
    MenuItem3->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem3->setColor(Color3B(0, 0, 0));
    MenuItem3->setPosition(Vec2( visibleSize.width/2,visibleSize.height/10*7));
    
    auto MenuItem4 = MenuItemFont::create("4.求多阶导数", CC_CALLBACK_1(FunctionMenu:: Function3Callback, this));
    MenuItem4->setScale(0.5);
    MenuItem4->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem4->setColor(Color3B(0, 0, 0));
    MenuItem4->setPosition(Vec2( visibleSize.width/2,visibleSize.height/10*6));
    
    auto MenuItem5 = MenuItemFont::create("5.多项式的乘法", CC_CALLBACK_1(FunctionMenu:: Function3Callback, this));
    MenuItem5->setScale(0.5);
    MenuItem5->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem5->setColor(Color3B(0, 0, 0));
    MenuItem5->setPosition(Vec2( visibleSize.width/2,visibleSize.height/10*5));
    
    auto MenuItem6 = MenuItemFont::create("6.求多阶导数", CC_CALLBACK_1(FunctionMenu:: Function3Callback, this));
    MenuItem6->setScale(0.5);
    MenuItem6->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem6->setColor(Color3B(0, 0, 0));
    MenuItem6->setPosition(Vec2( visibleSize.width/2,visibleSize.height/10*4));
    
    auto MenuItem7 = MenuItemFont::create("7.多项式的乘法", CC_CALLBACK_1(FunctionMenu:: Function3Callback, this));
    MenuItem7->setScale(0.5);
    MenuItem7->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem7->setColor(Color3B(0, 0, 0));
    MenuItem7->setPosition(Vec2( visibleSize.width/2,visibleSize.height/10*3));
    
    auto MenuItem8 = MenuItemFont::create("8.四则运算表达式求值", CC_CALLBACK_1(FunctionMenu:: Function8Callback, this));
    MenuItem8->setScale(0.5);
    MenuItem8->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem8->setColor(Color3B(0, 0, 0));
    MenuItem8->setPosition(Vec2( visibleSize.width/2,visibleSize.height/10*2));
    
    auto MenuItem9 = MenuItemFont::create("9.含未知数的表达式求值", CC_CALLBACK_1(FunctionMenu:: Function3Callback, this));
    MenuItem9->setScale(0.5);
    MenuItem9->setFontNameObj("fonts/STHeiti Medium.ttc");
    MenuItem9->setColor(Color3B(0, 0, 0));
    MenuItem9->setPosition(Vec2( visibleSize.width/2,visibleSize.height/10*1));
    
    
    auto FuncMenu = Menu::create(BackButton, MenuItem1,MenuItem2,MenuItem3,MenuItem4,MenuItem5,MenuItem6,MenuItem7,MenuItem8,MenuItem9, NULL);
    FuncMenu->setAnchorPoint(Vec2::ZERO);
    FuncMenu->setPosition(Vec2(origin.x ,origin.y ));
    //定位到左下角,向右向上是正方向
    this->addChild(FuncMenu,1);
    
    return true;
}

void FunctionMenu::menuCloseCallback(cocos2d::Ref *pSender){
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void FunctionMenu::Function1Callback(Ref* pSender)
{
    CCLOG("Trial");
    //Director::getInstance()->end();
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
//    exit(0);
//#endif
    auto F1_Scene = Func_1_Scene::createScene();
    
    Director::getInstance()->pushScene(F1_Scene);
    
}
void FunctionMenu::Function2Callback(Ref *pSender)
{
    CCLOG("Function2");
}
void FunctionMenu::Function3Callback(cocos2d::Ref *pSender)
{
    CCLOG("Function3");
}
void FunctionMenu::Function8Callback(Ref* pSender)
{
    auto F8_Scene = Func_8_Scene::createScene();
    
    Director::getInstance()->pushScene(F8_Scene);
    
}



