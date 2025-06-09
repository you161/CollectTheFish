
//FishOrange.h

#pragma once

#include "../HuEngine.h"

class FishOrange {
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