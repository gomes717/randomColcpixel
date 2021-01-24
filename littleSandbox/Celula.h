#pragma once
#include <vector>
#include <algorithm>

float const gravidade = 10;
const unsigned char color_vec[2][3] = { {65, 105,225},{105, 105, 105} };

typedef enum
{
	AZUL,
	CINZA
}COLOR;

enum MATERIAL 
{
	AGUA,
	PEDRA
};


typedef struct
{
	MATERIAL material;
	float densidade;
	COLOR cor;
	float pos_x;
	float pos_y;
	float dx;
	float dy;
	bool fixo;
	float temperatura;
}CelulaStruct;


void createCelula(MATERIAL material, float posx, float posy);

void destroyCelula(int posx, int posy);

bool hasCelula(int posx, int posy);

void updateCelula(std::vector<CelulaStruct>::iterator celula, float fElapsedTime);

std::vector<CelulaStruct>::iterator getVectorBegin();

std::vector<CelulaStruct>::iterator getVectorEnd();

bool collision(std::vector<CelulaStruct>::iterator celula);