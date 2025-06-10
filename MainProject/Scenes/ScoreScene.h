
#pragma once

#include "../HuEngine.h"
#include "../Classes/Player.h"
#include "../Scenes/MainScene.h"
#include "../Classes/PlayerData.h"



class ScoreScene : public HE::Scene
{
public:
    ScoreScene();
    virtual ~ScoreScene() { Terminate(); }

    void ResizeLayout() override;

    void Load() override;
    void Initialize() override;
    void Terminate() override;

    void Update(float deltaTime) override;

private:
    HE::Sprite sprite_;
    HE::Sound bgm_;
    Player player_;
    PlayerData playerdata_;


    int score_;
    HE::SpriteFont score_headline_;
    HE::SpriteFont score_text_;

};