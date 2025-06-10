//
// StartScene.cpp
//

#include "StartScene.h"

using namespace HE;



// initialize member variables.
StartScene::StartScene()
{

}

// rearrange UI to fit the size.
void StartScene::ResizeLayout()
{
    Scene::ResizeLayout();

}

// load resources.
void StartScene::Load()
{
    sprite_ = Sprite("Titlea.png");
    RenderingPath->AddSprite(&sprite_, 0);
    sprite_.params.siz = Math::Vector2(1280.0f, 720.0f);
    
   /* bgm_ = Sound("Sound/Gamestart.wav", Sound::LoopCount::BGM);
    bgm_.PlayFromTop();*/

    Scene::Load();
}

// initialize a variables.
void StartScene::Initialize()
{
    
}

// releasing resources required for termination.
void StartScene::Terminate()
{

}

// updates the scene.
void StartScene::Update(float deltaTime)
{

    if (InputSystem.Keyboard.isPressed.Space) {
        SceneManager.SetNextScene(NextScene::MainScene); 
    }

    Scene::Update(deltaTime);
}

