
//Player.h

#pragma once

#include "../HuEngine.h"

class Player {
public:
    void Load();
    void Initialize();
    void Update();

    HE::Math::Rectangle GetCollision();
    void OnCollision();

    HE::Math::Vector3 GetPosition() const { return sprite_.params.pos; }
    void SetInitialPosition();  

  
    
private:
    HE::Sprite sprite_;
    HE::Sprite collision_sprite_;

};
