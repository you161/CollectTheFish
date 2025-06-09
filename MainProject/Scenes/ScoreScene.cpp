//
// ScoreScene.cpp
//

#include "ScoreScene.h"

using namespace HE;

// initialize member variables.
ScoreScene::ScoreScene()
{
   
}

// rearrange UI to fit the size.
void ScoreScene::ResizeLayout()
{
    Scene::ResizeLayout();
}

// load resources.
void ScoreScene::Load()
{
    sprite_ = Sprite("ScoreA.png");
    RenderingPath->AddSprite(&sprite_, 0);
    sprite_.params.siz = Math::Vector2(1280.0f, 720.0f);

    bgm_ = Sound("Sound/Gameover.wav", Sound::LoopCount::BGM);
    bgm_.PlayFromTop();

    
    player_.Load();
   
    playerdata_.Load();
  

    Scene::Load();
}

// initialize a variables.
void ScoreScene::Initialize()
{
    player_.Initialize();
 
    playerdata_.Initialize();
}

// releasing resources required for termination.
void ScoreScene::Terminate()
{

}


// updates the scene.
void ScoreScene::Update(float deltaTime)
{
    player_.Update();
    
    if (InputSystem.Keyboard.isPressed.Enter) {
        // スペースキーでタイトル画面に戻る
        SceneManager.SetNextScene(NextScene::StartScene);
    }

    if (InputSystem.Keyboard.isPressed.Space) {
       
        SceneManager.SetNextScene(NextScene::MainScene);
    }

    Scene::Update(deltaTime);
}



