#include "caillou.h"
#include "Sprites.h"

Caillou::Caillou(RenderWindow &app, float posX, float posY) : Bloc(app, P_CAILLOU, posX, posY)
{
	img->Draw();
	Type = "Caillou";
	sellPrice = 1000;
}

void Caillou::Do(vector<Ennemy*> &v, float gameTime)
{
	
}