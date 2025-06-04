
//FishBrown.cpp

#include "FishBrown.h"

using namespace HE;

void FishBrown::Load()
{

    sprite_ = Sprite("fish_brown.png");
    RenderingPath->AddSprite(&sprite_, -50);
    RenderingPath->AddSprite(&collision_sprite_, 1);
}

void FishBrown::Initialize()
{

    sprite_.params.siz = Math::Vector2(64.0f, 64.0f);
    SetInitialPosition();
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    collision_sprite_.params.color = Color(0, 0, 255);
    collision_sprite_.params.opacity = 0.0f;


    // �A�j���[�V�����̐ݒ�
    //sprite_.anim = Sprite::Anim();
    //sprite_.anim.repeataFishBrownle = true;                       // ���[�v���邩���Ȃ���
    //sprite_.anim.drawRectAnim.frameRate = 4;             // �A�j���[�V�����̑��x
    //sprite_.anim.drawRectAnim.frameCount = 1;             // �摜�ɃA�j���[�V���������R�}���邩
    //sprite_.anim.drawRectAnim.horizontalFrameCount = 1;   // ���ɕ���ł���R�}��


}

void FishBrown::Update()
{

    sprite_.params.pos.x += 400.0f * Time.deltaTime;
    if (sprite_.params.pos.x >= 1280.0f)
        SetInitialPosition();
}

Math::Rectangle FishBrown::GetCollision()
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

void FishBrown::OnCollision()
{
    SetInitialPosition();
}

void FishBrown::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(-80.0f, 400.0f);
}