#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Celula.h"





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
		createWorld(ScreenHeight(), ScreenWidth());
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		/*
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(255, 255, 255));*/

		// called once per frame, draws random coloured pixels

		int x = PixelGameEngine::GetMousePos().x;
		int y = PixelGameEngine::GetMousePos().y;
		if (PixelGameEngine::GetMouse(0).bHeld && !hasCelula(x, y))
			createCelula(AGUA, x, y);

		if (PixelGameEngine::GetMouse(1).bHeld && !hasCelula(x, y))
			createCelula(PEDRA, x, y);
		if (PixelGameEngine::GetMouse(2).bHeld && hasCelula(x, y))
		{
			Draw(x, y, olc::Pixel(255, 255, 255, 255));
			destroyCelula(x, y);
		}
			
		
		for (std::vector<CelulaStruct>::iterator pixel_aux = getVectorBegin(); pixel_aux != getVectorEnd(); ++pixel_aux)
		{
			Draw(pixel_aux->pos_x, pixel_aux->pos_y, olc::Pixel(255,255,255,255));
			pixel_aux = updateCelula(pixel_aux, fElapsedTime);

			if (pixel_aux->pos_y > PixelGameEngine::ScreenHeight()) {
				destroyCelula(pixel_aux->pos_x, pixel_aux->pos_y);
				break;
			}
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
	if (demo.Construct(128, 120, 8, 8))
		demo.Start();
	destroyWorld();
	return 0;
}
