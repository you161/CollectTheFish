
//Fishpink.cpp

#include "Fishpink.h"

using namespace HE;

void Fishpink::Load()
{

    sprite_ = Sprite("fish_pink.png");
    RenderingPath->AddSprite(&sprite_, -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void Fishpink::Initialize(HE::Math::Vector2 initial)
{

    sprite_.params.siz = Math::Vector2(64.0f, 64.0f);
    sprite_.params.pos = initial;
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    collision_sprite_.params.color = Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;


   
}

void Fishpink::Update()
{

    sprite_.params.pos.x += 200.0f * Time.deltaTime;
    if (sprite_.params.pos.x >= 1280.0f)
        SetInitialPosition();
}

Math::Rectangle Fishpink::GetCollision()
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

void Fishpink::OnCollision()
{
    SetInitialPosition();
}

void Fishpink::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(-80.0f, 200.0f);
}