
//A.h

#pragma once

#include "../HuEngine.h"

class A {
public:
    void Load();
    void Initialize(HE::Math::Vector2 initial);
    void Update();
    void OnCollision();  
    HE::Math::Rectangle GetCollision();  
    void SetInitialPosition();

private:
    HE::Sprite sprite_;
    HE::Sprite collision_sprite_;
};