
//FishOrange.cpp

#include "FishOrange.h"

using namespace HE;

void FishOrange::Load()
{

    sprite_ = Sprite("fish_orange.png");
    RenderingPath->AddSprite(&sprite_, -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void FishOrange::Initialize()
{

    sprite_.params.siz = Math::Vector2(64.0f, 64.0f);
    SetInitialPosition();
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    collision_sprite_.params.color = Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;

}

void FishOrange::Update()
{

    sprite_.params.pos.x += 600.0f * Time.deltaTime;
    if (sprite_.params.pos.x >= 1280.0f)
        sprite_.params.pos = Math::Vector2(-80.0f, Random::GetRandom(450.0f, 680.0f));
}

Math::Rectangle FishOrange::GetCollision()
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

void FishOrange::OnCollision()
{
    sprite_.params.pos = Math::Vector2(-80.0f, Random::GetRandom(450.0f, 680.0f));
}

void FishOrange::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(-80.0f, 480.0f);
}