#include "Celula.h"


std::vector<CelulaStruct> vec_pixels;
std::vector<CelulaStruct> vec_cel_nao_fixo;
std::vector<CelulaStruct> vec_cel_fixo;

void createCelula(MATERIAL material, float posx, float posy)
{
	CelulaStruct cel_aux;
	switch (material)
	{
	case AGUA:
		cel_aux.densidade = 1.0f;
		cel_aux.cor = AZUL;
		cel_aux.dx = 0;
		cel_aux.dy = 0;
		cel_aux.pos_x = posx;
		cel_aux.pos_y = posy;
		cel_aux.material = material;
		cel_aux.fixo = false;
		cel_aux.temperatura = 25.f;
		break;
	case PEDRA:
		cel_aux.densidade = 4.0f;
		cel_aux.cor = CINZA;
		cel_aux.dx = 0;
		cel_aux.dy = 0;
		cel_aux.pos_x = posx;
		cel_aux.pos_y = posy;
		cel_aux.material = material;
		cel_aux.fixo = true;
		cel_aux.temperatura = 25.f;
		break;
	default:
		printf("material não existe");
		break;
	}

	vec_pixels.push_back(cel_aux);

}

void destroyCelula(int posx, int posy)
{
	for (std::vector<CelulaStruct>::iterator pixel_aux = vec_pixels.begin(); pixel_aux != vec_pixels.end(); ++pixel_aux)
	{
		if ((int)pixel_aux->pos_x == posx && (int)pixel_aux->pos_y == posy)
		{
			vec_pixels.erase(pixel_aux);
			break;
		}
	}
}

void updateCelula(std::vector<CelulaStruct>::iterator celula, float fElapsedTime)
{


}

std::vector<CelulaStruct>::iterator getVectorBegin()
{
	return vec_pixels.begin();
}

std::vector<CelulaStruct>::iterator getVectorEnd()
{
	return vec_pixels.end();
}

//arrumar essa funçao depois, foi criada apenas para um teste, muito mal otimizada
bool hasCelula(int posx, int posy)
{
	if (vec_pixels.empty())
		return false;
	for (std::vector<CelulaStruct>::iterator pixel_aux = vec_pixels.begin(); pixel_aux != vec_pixels.end(); ++pixel_aux)
	{
		if ((int)(pixel_aux->pos_x) == posx && (int)(pixel_aux->pos_y) == posy)
			return true;
	}
	return false;
}

//colisao apenas para fluidos no momento, nem um pouco descente, varios erros
bool collision(std::vector<CelulaStruct>::iterator celula)
{
	if (!celula->fixo && hasCelula(celula->pos_x, celula->pos_y + 1)) {
		celula->dy = 0;
		bool esq = hasCelula(celula->pos_x - 1, celula->pos_y);
		bool dir = hasCelula(celula->pos_x + 1, celula->pos_y);

		if (!dir)
			celula->dx = 1;
		else if (!esq)
			celula->dx = -1;
		else
			celula->dx = 0;

		return true;
	}
	return false;
}