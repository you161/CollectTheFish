
//Fishgreen.cpp

#include "Fishgreen.h"

using namespace HE;

void Fishgreen::Load()
{

    sprite_ = Sprite("fish_green.png");
    RenderingPath->AddSprite(&sprite_, -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void Fishgreen::Initialize()
{

    sprite_.params.siz = Math::Vector2(64.0f, 64.0f);
    SetInitialPosition();
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    collision_sprite_.params.color = Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;


    // アニメーションの設定
    //sprite_.anim = Sprite::Anim();
    //sprite_.anim.repeataFishgreenle = true;                       // ループするかしないか
    //sprite_.anim.drawRectAnim.frameRate = 4;             // アニメーションの速度
    //sprite_.anim.drawRectAnim.frameCount = 1;             // 画像にアニメーションが何コマあるか
    //sprite_.anim.drawRectAnim.horizontalFrameCount = 1;   // 横に並んでいるコマ数


}

void Fishgreen::Update()
{

    sprite_.params.pos.x += 80.0f * Time.deltaTime;
    if (sprite_.params.pos.x >= 1280.0f) {
        sprite_.params.pos = Math::Vector2(-80.0f, Random::GetRandom(300.0f,680.0f));
    }
}

Math::Rectangle Fishgreen::GetCollision()
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

void Fishgreen::OnCollision()
{
    sprite_.params.pos = Math::Vector2(-80.0f, Random::GetRandom(300.0f, 680.0f));
}

void Fishgreen::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(-80.0f, 600.0f);
}