
//
// BG.cpp
//

#include "BG.h"

using namespace HE;

void BG::Load()
{
    sprite_ = Sprite("BG_.png");
    RenderingPath->AddSprite(&sprite_, -100);
}

void BG::Initialize()
{
    sprite_.params.siz = Math::Vector2(1280.0f, 720.0f);
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);
}

void BG::Update()
{

}
