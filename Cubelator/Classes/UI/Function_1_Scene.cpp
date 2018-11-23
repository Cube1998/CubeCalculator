//
//  Function_1_Scene.cpp
//  Cubelator
//
//  Created by 张大方 on 2018/11/19.
//

#include "Function_1_Scene.hpp"


Scene* Func_1_Scene::createScene(){
    return Func_1_Scene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool Func_1_Scene::init(){
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
    
    //set title
    Title->setFontNameObj("fonts/STHeiti Medium.ttc");
    Title->setColor(Color3B(0, 0, 0));
    Title->setPosition(Vec2( visibleSize.width/2,visibleSize.height-Title->getContentSize().height+30));
    
    //Init Dimension INPUT Field
    auto DimensionField = TextField::create("Input Dimension", "Arial", 20);
    DimensionField->setPosition(Vec2(visibleSize.width/2,visibleSize.height/10*8));
    DimensionField->setTextColor(Color4B(Color3B(55, 55, 55)));
    this->addChild(DimensionField,3);
    DimensionField->addEventListener(CC_CALLBACK_2(Func_1_Scene::DimensionInputEvent, this));
    DimensionField->setCursorEnabled(true);
    
    
    //Init TextField of Vector1
    auto Vector1Field = TextField::create("Input Vector1", "Arial", 20);
    Vector1Field->setPosition(Vec2(visibleSize.width/2,visibleSize.height/10*7));
    Vector1Field->setTextColor(Color4B(Color3B(55, 55, 55)));
    this->addChild(Vector1Field);
    Vector1Field->addEventListener(CC_CALLBACK_2(Func_1_Scene::Vector1_InputEvent, this));
    Vector1Field->setCursorEnabled(true);
    
    
    //Init TextField of Vector2
    auto Vector2Field = TextField::create("Input Vector2", "Arial", 20);
    Vector2Field->setPosition(Vec2(visibleSize.width/2,visibleSize.height/10*6));
    Vector2Field->setTextColor(Color4B(Color3B(55, 55, 55)));
    this->addChild(Vector2Field);
    Vector2Field->addEventListener(CC_CALLBACK_2(Func_1_Scene::Vector2_InputEvent, this));
    Vector2Field->setCursorEnabled(true);
    
    
    
    //Init back button;
    auto BackButton = MenuItemImage::create("back_128.png", "back_128.png", CC_CALLBACK_1(Func_1_Scene::menuBackCallback, this));
    BackButton->setScale(0.5);
    BackButton->setAnchorPoint(Vec2::ZERO);
    BackButton->setPosition(20,visibleSize.height/2);
    
    this->AddBox->setScale(2);
    this->AddBox->setPosition(Vec2(AddBox->getContentSize().width+20 ,visibleSize.height-AddBox->getContentSize().height));
    this->AddBox->setCallback(CC_CALLBACK_1(Func_1_Scene::switch2Add, this));
    
    
    this->MinusBox->setScale(2);
    this->MinusBox->setPosition(Vec2(visibleSize.width - AddBox->getContentSize().width-20,visibleSize.height-AddBox->getContentSize().height));
    this->MinusBox->setCallback(CC_CALLBACK_1(Func_1_Scene::switch2Minus , this));
    
    
    //Init Compute Button
    auto ComputeButton = MenuItemImage::create("Calcu1.png","Calcu2.png",CC_CALLBACK_1(Func_1_Scene::Compute, this));
    ComputeButton->setAnchorPoint(Vec2::ZERO);
    ComputeButton->setPosition(Vec2(visibleSize.width-ComputeButton->getContentSize().width-10,ComputeButton->getContentSize().height));
    
    
    
    
    auto menu = Menu::create(Title,AddBox,MinusBox,BackButton,ComputeButton,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
    
    
}

void Func_1_Scene::menuBackCallback(Ref* pSender){
    Director::getInstance()->popScene();
}
void Func_1_Scene::Compute(Ref *pSender){
    
    
    
    string2vector(x, x_vector);
    string2vector(y, y_vector);
    
    Vector1 v1(dimension,x);
    Vector1 v2(dimension,y);
    if(this->AddOrMinus){v1.Add(v2);}
    else{v1.Minus(v2);}
    this->Result->setString(v1.getVecInStr());
    
    
    
}
void Func_1_Scene:: textFieldEvent(Ref * sender, TextField::EventType type){
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
void Func_1_Scene::DimensionInputEvent(Ref *sender, TextField::EventType type){
    TextField *textField = dynamic_cast<TextField *>(sender);
    int tmp;
    switch (type) {
            
        case TextField::EventType::ATTACH_WITH_IME :
            log("Start typing");
            break;
        case TextField::EventType::DETACH_WITH_IME :
            log("End typing");
            break;
        case TextField::EventType::INSERT_TEXT :
            tmp = stoi(textField->getString());
            if(tmp<=0)
            {
                log("Wrong Dimension");
                break;
            }
            this->dimension = tmp;
            log("%s",textField->getString().c_str());
            break;
        case TextField::EventType::DELETE_BACKWARD :
            tmp = stoi(textField->getString());
            if(tmp<=0)
            {
                log("Wrong Dimension");
                break;
            }
            this->dimension = tmp;
            break;
        default:
            break;
    }
}

void Func_1_Scene::Vector1_InputEvent(Ref *sender, TextField::EventType type){
    TextField *textField = dynamic_cast<TextField *>(sender);
    switch (type) {
            
        case TextField::EventType::ATTACH_WITH_IME :
            log("Start typing");
            break;
        case TextField::EventType::DETACH_WITH_IME :
            log("End typing");
            break;
        case TextField::EventType::INSERT_TEXT :
            this->x_vector = textField->getString();
            log("%s",textField->getString().c_str());
            break;
        case TextField::EventType::DELETE_BACKWARD :
            this->x_vector = textField->getString();
            log("%s",textField->getString().c_str());
            break;
        default:
            break;
    }
}

void Func_1_Scene::Vector2_InputEvent(Ref *sender, TextField::EventType type){
    TextField *textField = dynamic_cast<TextField *>(sender);
    switch (type) {
            
        case TextField::EventType::ATTACH_WITH_IME :
            log("Start typing");
            break;
        case TextField::EventType::DETACH_WITH_IME :
            log("End typing");
            break;
        case TextField::EventType::INSERT_TEXT :
            this->y_vector = textField->getString();
            log("%s",textField->getString().c_str());
            break;
        case TextField::EventType::DELETE_BACKWARD :
            this->y_vector = textField->getString();
            log("%s",textField->getString().c_str());
            break;
        default:
            break;
    }
}

void Func_1_Scene::string2vector(int* Vector, string vector){
    char * cstr = new char [vector.length()+1];
    std::strcpy (cstr, vector.c_str());
    string tmp;
    const char* d = " ";
    char* p;
    p = strtok(cstr, d);
    int t = 0;
    while(p)
    {
        tmp = p;
        Vector[t++] = stoi(tmp);
        p=strtok(NULL,d);
    }
}

void Func_1_Scene::switch2Add(Ref *sender){
    this->AddOrMinus = true;
    this->Title->setString("同维度向量的加法");
}
void Func_1_Scene::switch2Minus(Ref *sender){
    this->AddOrMinus = false;
    this->Title->setString("同维度向量的减法");
}
