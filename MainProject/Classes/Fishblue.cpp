
//Fishblue.cpp

#include "Fishblue.h"

using namespace HE;

void Fishblue::Load()
{

    sprite_ = Sprite("fish_blueA.png");
    RenderingPath->AddSprite(&sprite_, -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void Fishblue::Initialize()
{

    sprite_.params.siz = Math::Vector2(128.0f, 128.0f);
    SetInitialPosition();
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    collision_sprite_.params.color = Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;


    // アニメーションの設定
    //sprite_.anim = Sprite::Anim();
    //sprite_.anim.repeataFishbluele = true;                       // ループするかしないか
    //sprite_.anim.drawRectAnim.frameRate = 4;             // アニメーションの速度
    //sprite_.anim.drawRectAnim.frameCount = 1;             // 画像にアニメーションが何コマあるか
    //sprite_.anim.drawRectAnim.horizontalFrameCount = 1;   // 横に並んでいるコマ数


}

void Fishblue::Update()
{

    sprite_.params.pos.x += 150.0f * Time.deltaTime;
    if (sprite_.params.pos.x >= 1280.0f)
        sprite_.params.pos = Math::Vector2(-140.0f, Random::GetRandom(400.0f,600.0f));
}

Math::Rectangle Fishblue::GetCollision()
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

void Fishblue::OnCollision()
{
    SetInitialPosition();
}

void Fishblue::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(-140.0f, 500.0f);
}