#include "Celula.h"


CelulaStruct createCelula(int material, float posx, float posy)
{
	CelulaStruct cel_aux;
	cel_aux.densidade = 0;
	cel_aux.cor = AZUL;
	cel_aux.dx = 0;
	cel_aux.dy = 0;
	cel_aux.pos_x = 0;
	cel_aux.pos_y = 0;
	cel_aux.material = material;
	switch (material)
	{
	case 0:
		cel_aux.densidade = 1.0f;
		cel_aux.cor = AZUL;
		cel_aux.dx = 0;
		cel_aux.dy = 0;
		cel_aux.pos_x = posx;
		cel_aux.pos_y = posy;
		cel_aux.material = material;
		cel_aux.fixo = false;
		break;
	case 1:
		cel_aux.densidade = 4.0f;
		cel_aux.cor = CINZA;
		cel_aux.dx = 0;
		cel_aux.dy = 0;
		cel_aux.pos_x = posx;
		cel_aux.pos_y = posy;
		cel_aux.material = material;
		cel_aux.fixo = true;
		break;
	default:
		printf("material não existe");
		break;
	}

	return cel_aux;

}

void destroyCelula(CelulaStruct celula)
{

}