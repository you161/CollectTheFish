
//
// Player.cpp
//

#include "Player.h"

using namespace HE;

void Player::Load()
{
    sprite_ = Sprite("CCCat.png");
    RenderingPath->AddSprite(&sprite_, 0);
    RenderingPath->AddSprite(&collision_sprite_, 1);

}


void Player::Initialize()
{
    sprite_.params.siz = Math::Vector2(84.0f, 63.0f);
    SetInitialPosition();
   

    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));


    // 衝突範囲の表示設定
    collision_sprite_.params.color = Color(255, 0, 0);  // 色
    collision_sprite_.params.opacity = 0.0f;              // 透明度


    RenderingPath->AddSprite(&sprite_);
}

void Player::Update()
{
    //上下左右　
    Math::Vector2 direction;

    if (InputSystem.Keyboard.isPressed.Right)
        direction += Math::Vector2(1, 0);
    if (InputSystem.Keyboard.isPressed.Left)
        direction += Math::Vector2(-1, 0);
    /*if (InputSystem.Keyboard.isPressed.Down)*/
    sprite_.params.pos.y += 100.0f * Time.deltaTime;
    

    //矢印の長さを1にする
    direction.Normalize();

    auto prev_pos = sprite_.params.pos;
    sprite_.params.pos += direction * 150.0f * Time.deltaTime;

    //画面の外に出ないようにする
    sprite_.params.pos.x = std::clamp(sprite_.params.pos.x, 0.0f, 1280.0f - 84.0f);
    sprite_.params.pos.y = std::clamp(sprite_.params.pos.y, 0.0f, 720.0f - 63.0f);

    if (sprite_.params.pos.y >= 720.0f - 63.0f) {
        sprite_.params.pos.y = -64.0f;
    }

}

Math::Rectangle Player::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)(sprite_.params.pos.x);
    collision.y = (long)(sprite_.params.pos.y);
    collision.width = (long)(sprite_.params.siz.x);
    collision.height = (long)(sprite_.params.siz.y);


    // 衝突範囲表示設定
    collision_sprite_.params.pos.x = (float)collision.x;
    collision_sprite_.params.pos.y = (float)collision.y;
    collision_sprite_.params.siz.x = (float)collision.width;
    collision_sprite_.params.siz.y = (float)collision.height;


    return collision;
}


void Player::OnCollision()
{
    SetInitialPosition();
}

void Player::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(
        (RenderingPath->GetLogicalWidth() - sprite_.params.siz.x) / 2.0f,
        sprite_.params.pos.y = 0.0f
    );
}





