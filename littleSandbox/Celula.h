#pragma once
#include <iostream>
using namespace std;

const unsigned char color_vec[2][3] = { {65, 105,225},{105, 105, 105} };

typedef enum
{
	AZUL,
	CINZA
}COLOR;

enum class MATERIAL 
{
	AGUA,
	PEDRA
};


typedef struct
{
	int material;
	float densidade;
	COLOR cor;
	float pos_x;
	float pos_y;
	float dx;
	float dy;
	bool fixo;
}CelulaStruct;

CelulaStruct createCelula(int material, float posx, float posy);

void destroyCelula(CelulaStruct celula);