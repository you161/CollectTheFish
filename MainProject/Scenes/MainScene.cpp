
//
// MainScene.cpp
//

#include "MainScene.h"
#include"DontDestroyOnLoad.h"

using namespace HE;
using namespace std;

// initialize member variables.
MainScene::MainScene()
{

}
// rearrange UI to fit the size.
void MainScene::ResizeLayout()
{
    Scene::ResizeLayout();
}
// load resources.
void MainScene::Load()
{

    sprite_ = Sprite("fish_grey.png");
    RenderingPath->AddSprite(&sprite_, -50);


    bg_.     Load();

    player_.Load();
    a_.Load();
    fo_.Load();
    fb_.Load();
    fg_.Load();
    fp_.Load();
    fB_.Load();
    fBA_.Load();

    playerdata_.Load();
    playerlife_.Load();

    bgm_ = Sound("Sound/sea.wav", Sound::LoopCount::BGM);
    bgm_.PlayFromTop();

    //se_ = Sound("Sound/PushA.wav", Sound::LoopCount::SE);
    //se_.PlayFromTop();

    Scene::Load();
}
// initialize a variables.
void MainScene::Initialize()
{

    sprite_.params.siz = Math::Vector2(64.0f, 64.0f);
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);

    bg_.Initialize();
    player_.Initialize();
    a_.Initialize(Math::Vector2(-64.0f,300.0f));
    fo_.Initialize();
    fb_.Initialize();
    fB_.Initialize();
    fBA_.Initialize();
    fg_.Initialize();
    fp_.Initialize(Math::Vector2(-64.0f * 1.0f,200.0f));
    playerdata_.Initialize();
    playerlife_.Initialize();
}
// releasing resources required for termination.
void MainScene::Terminate()
{

}
// updates the scene.
void MainScene::Update(float deltaTime)
{ 


    sprite_.params.pos.x += 200.0f * Time.deltaTime;
    if (sprite_.params.pos.x >= 1280.0f) {
        sprite_.params.pos.x = 0.0f;

        int rest = playerlife_.GetLife();
        rest -= 1;
        playerlife_.SetLife(rest);

        if(rest < 0){
            DontDestroy.playerdata_ = playerdata_;
            SceneManager.SetNextScene(NextScene::ScoreScene);
        }
    }


 bg_.Update();
 player_.Update();
 a_.Update();
 fo_.Update();
 fb_.Update();
 fB_.Update();
 fBA_.Update();
 fg_.Update();
 fp_.Update();

 Math::Rectangle player_collision = player_.GetCollision();
 Math::Rectangle a_collision = a_.GetCollision();
 Math::Rectangle fo_collision = fo_.GetCollision();
 Math::Rectangle fb_collision = fb_.GetCollision();
 Math::Rectangle fB_collision = fB_.GetCollision();
 Math::Rectangle fBA_collision = fBA_.GetCollision();
 Math::Rectangle fg_collision = fg_.GetCollision();
 Math::Rectangle fp_collision = fp_.GetCollision();

 if (player_collision.Intersects(a_collision)) {
     a_.OnCollision();

     int score = playerdata_.GetScore();
     score += 10;
     playerdata_.SetScore(score);
 }


 if (player_collision.Intersects(fo_collision)) {  
     fo_.OnCollision();

     int score = playerdata_.GetScore();
     score += 30;
     playerdata_.SetScore(score);
 } 
 
 if (player_collision.Intersects(fb_collision)) {  
     fb_.OnCollision();

     int score = playerdata_.GetScore();
     score += 20;
     playerdata_.SetScore(score);
 }

 if (player_collision.Intersects(fg_collision)) { 
     fg_.OnCollision();

     int score = playerdata_.GetScore();
     score += 50;
     playerdata_.SetScore(score);
 }

 if (player_collision.Intersects(fp_collision)) {
     fp_.OnCollision();


     int score = playerdata_.GetScore();
     score += 5;
     playerdata_.SetScore(score);
 }


 if (player_collision.Intersects(fB_collision)) {   
     fB_.OnCollision();

     int score = playerdata_.GetScore();
     score -= 50;
     playerdata_.SetScore(score);
 }



 if (player_collision.Intersects(fBA_collision)) {
     fBA_.OnCollision();

     int score = playerdata_.GetScore();
     score -= 50;
     playerdata_.SetScore(score);
 }

 /*if (InputSystem.Keyboard.wasPressedThisFrame.G) {
     DontDestroy.playerdata_ = playerdata_;

     SceneManager.SetNextScene(NextScene::ScoreScene);
 }*/

     Scene::Update(deltaTime);
}