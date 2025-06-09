
//FishBrownA.cpp

#include "FishBrownA.h"

using namespace HE;

void FishBrownA::Load()
{

    sprite_ = Sprite("fish_brown.png");
    RenderingPath->AddSprite(&sprite_, -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void FishBrownA::Initialize()
{

    sprite_.params.siz = Math::Vector2(64.0f, 64.0f);
    SetInitialPosition();
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    collision_sprite_.params.color = Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;

}

void FishBrownA::Update()
{

    sprite_.params.pos.x -= 400.0f * Time.deltaTime;
    sprite_.params.enableMirror();
    if (sprite_.params.pos.x <= 0.0f)
        sprite_.params.pos = Math::Vector2(1300.0f, Random::GetRandom(100.0f, 680.0f));
}

Math::Rectangle FishBrownA::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)sprite_.params.pos.x;
    collision.y = (long)sprite_.params.pos.y;
    collision.width = (long)sprite_.params.siz.x;
    collision.height = (long)sprite_.params.siz.y;


    collision_sprite_.params.pos.x = (float)collision.x;
    collision_sprite_.params.pos.y = (float)collision.y;
    collision_sprite_.params.siz.x = (float)collision.width;
    collision_sprite_.params.siz.y = (float)collision.height;



    return collision;
}

void FishBrownA::OnCollision()
{
    sprite_.params.pos = Math::Vector2(1300.0f, Random::GetRandom(100.0f, 680.0f));
}

void FishBrownA::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(1300.0f, 250.0f);
}