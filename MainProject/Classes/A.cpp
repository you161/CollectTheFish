
//Treiler.cpp

#include "A.h"

using namespace HE;

void A::Load()
{

    sprite_ = Sprite("fish_red.png");
    RenderingPath->AddSprite(&sprite_, -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void A::Initialize(HE::Math::Vector2 initial)
{

    sprite_.params.siz = Math::Vector2(64.0f, 64.0f);
    sprite_.params.pos = initial;
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    collision_sprite_.params.color = Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;

}

void A::Update()
{
   
    sprite_.params.pos.x += 270.0f * Time.deltaTime;
    if (sprite_.params.pos.x >= 1280.0f) {
        sprite_.params.pos = Math::Vector2(-80.0f,Random::GetRandom(100.0f, 400.0f));
    }
      
}

Math::Rectangle A::GetCollision()
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

void A::OnCollision()
{
    sprite_.params.pos = Math::Vector2(-80.0f, Random::GetRandom(100.0f, 400.0f));
}

void A::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(-80.0f, 300.0f);
}