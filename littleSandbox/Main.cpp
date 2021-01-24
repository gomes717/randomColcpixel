#define OLC_PGE_APPLICATION
#include "Celula.h"
#include "olcPixelGameEngine.h"
#include <iostream>

static float gravidade = 10;
std::vector<CelulaStruct> vec_pixels;

void cleanScreen();

// Override base class with your custom functionality
class SandBox : public olc::PixelGameEngine
{
public:
	SandBox()
	{
		// Name you application
		sAppName = "Sandbox";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(255, 255, 255));
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(255, 255, 255));

		// called once per frame, draws random coloured pixels

		if (PixelGameEngine::GetMouse(0).bHeld)
			vec_pixels.push_back(createCelula(0, PixelGameEngine::GetMousePos().x, PixelGameEngine::GetMousePos().y));

		if (PixelGameEngine::GetMouse(1).bHeld)
			vec_pixels.push_back(createCelula(1, PixelGameEngine::GetMousePos().x, PixelGameEngine::GetMousePos().y));

		for (std::vector<CelulaStruct>::iterator pixel_aux = vec_pixels.begin(); pixel_aux != vec_pixels.end(); ++pixel_aux)
		{
			if(!pixel_aux->fixo)
				pixel_aux->dy += gravidade * fElapsedTime;
				pixel_aux->pos_x += pixel_aux->dx * fElapsedTime;
				pixel_aux->pos_y += pixel_aux->dy * fElapsedTime;
			Draw(pixel_aux->pos_x, pixel_aux->pos_y, olc::Pixel(color_vec[pixel_aux->cor][0],
																color_vec[pixel_aux->cor][1],
																color_vec[pixel_aux->cor][2],
																255));
		}
		return true;
	}
};

int main()
{
	SandBox demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}
