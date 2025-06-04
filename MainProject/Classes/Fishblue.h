
//Fishblue.h

#pragma once

#include "../HuEngine.h"

class Fishblue {
public:
    void Load();
    void Initialize();
    void Update();
    void OnCollision();  
    HE::Math::Rectangle GetCollision();  
    void SetInitialPosition();

private:
    HE::Sprite sprite_;
    HE::Sprite collision_sprite_;
};