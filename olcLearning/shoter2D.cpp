#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>

class Shoter2D : public olc::PixelGameEngine
{
public:
    struct {
        float x,y;
        float dx,dy;
        int body_x,body_y;
        char lado;
    } player;

    struct shot 
    {
        float x,y,dx,dy;
    };

    std::vector<struct shot> vec_shots;

    float gravity;

	Shoter2D()
	{
		// Name you application
		sAppName = "2D_SHOTER";
        gravity = 20.0f;
	}
public:
	bool OnUserCreate() override
	{
		for (int32_t x = 0; x < ScreenWidth(); x++){
			for (int32_t y = 0; y < ScreenHeight(); y++){
                if(y<=200)
				    Draw(x, y, olc::Pixel(255,255,255,255));
                else
                    Draw(x, y, olc::Pixel(127,63,0,255));
            }
        }

        player.x = 20.0f;
        player.y = 210.0f;
        player.dx = 0.0f;
        player.dy = 0.0f;
        player.body_x = 2;
        player.body_y = 2;
        player.lado = 1;
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
        //clean world
        for (int32_t x = 0; x < ScreenWidth(); x++){
			for (int32_t y = 0; y < ScreenHeight(); y++){
                if(y<=200)
				    Draw(x, y, olc::Pixel(255,255,255,255));
                else
                    Draw(x, y, olc::Pixel(127,63,0,255));
            }
        }

        //movimento x
        if(PixelGameEngine::GetKey(olc::LEFT).bHeld){
            player.dx = -20.0f;
            player.lado = -1;
        }else if(PixelGameEngine::GetKey(olc::RIGHT).bHeld){
            player.dx = 20.0f;
            player.lado = 1;
        }else
            player.dx = 0.0f;
        // y
        if(PixelGameEngine::GetKey(olc::UP).bPressed)
            player.dy = -20.0f;

        if(PixelGameEngine::GetKey(olc::SPACE).bPressed)
        {
            struct shot shots;
            shots.dy = 0.0f;
            shots.dx = 50.0f*player.lado;
            shots.x = player.x;
            shots.y = player.y - 1;
            vec_shots.push_back(shots);
        }

        player.dy += gravity*fElapsedTime;
        player.x += player.dx*fElapsedTime;
        player.y += player.dy*fElapsedTime;

        if(player.y > 200)
            player.y = 200;

 
        //draw player
       for(int b_x = player.x - player.body_x ; b_x < player.x;b_x++)
            for(int b_y = player.y - player.body_y; b_y < player.y + 1;b_y++)
                Draw(b_x,b_y,olc::Pixel(0,255,0,255));

        //draw shots
        for (std::vector<struct shot>::iterator shot_aux = vec_shots.begin() ; shot_aux != vec_shots.end(); ++shot_aux)
        {
            shot_aux->dy += gravity*fElapsedTime;
            shot_aux->x += shot_aux->dx*fElapsedTime;
            shot_aux->y += shot_aux->dy*fElapsedTime;                                 
            Draw(shot_aux->x,shot_aux->y,olc::Pixel(0,0,0,255));
        }



		return true;
	}
};
int main()
{
	Shoter2D demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}