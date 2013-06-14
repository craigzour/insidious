#include "tour.h"
#include "Sprites.h"

#include <iostream>

Tour::Tour(RenderWindow &app, float posX, float posY) : Bloc(app, P_TOUR, posX, posY)
{
	img->Draw();
	Type = "Tour";
    sellPrice = 500;
    price = 1000;
    
	pX = posX;
	pY = posY;

	strenght = 20;

	shot = false;
	es = 0;
    
    rayon = 80;

	mis = new Sprites(app);
}

Tour::~Tour()
{
	delete mis;
}

void Tour::Do(vector<Ennemy*> &v, float gameTime)
{
	if(this->GetVie() > 0)
	{
		if(!shot)
		{
			for(int i = 0; i < (signed)v.size(); i++)
			{
				if(v[i]->checkAlive() && isIn(v[i]->getPx(), v[i]->getPy()))
				{
					es = i;
					shot = true;
					break;
				}
			}
		}
	
		if(shot && isIn(v[es]->getPx(), v[es]->getPy()))
		{
			mis->shot(gameTime, *this, *v[es]);
        
			if(!v[es]->checkAlive())
			{
				shot = false;
				this->SetVie(this->GetVie() - 5);
			}
		}
		else
		{
			shot = false;
		}
	}
	else
	{
		shot = false;
	}
}	

float Tour::getPx()
{
	return pX;
}

float Tour::getPy()
{
	return pY;
}

int Tour::getPrice()
{
    return price;
}

bool Tour::getShot()
{
	return shot;
}

void Tour::setShot(bool c)
{
	shot = c;
}

bool Tour::isIn(float x, float y)
{
	float dist = ((x - pX) * (x - pX)) + ((y - pY) * (y - pY));

	if(dist > (rayon * rayon))
		return false;
	else
		return true;

	/*if(((pX - 100) < x) && ((pX + 100) > x))
	{
		if(((pY - 100) < y) && ((pY + 100) > y))
		{
			return true;
		}
	}

	return false;*/
}