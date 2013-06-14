#include "vide.h"
#include "Sprites.h"

Vide::Vide(RenderWindow &app, float posX, float posY) : Bloc(app, P_HERBE, posX, posY)
{
	img->Draw();
	Type = "Vide";
	sellPrice = 0;
}

void Vide::Do(vector<Ennemy*> &v, float gameTime)
{

}