#include "ennemy.h"

#include <iostream>

Ennemy::Ennemy(RenderWindow &app, float posX, float posY)
{
	img = new Sprites(app, SPR_SOLDAT1, posX, posY);
	img->Cut(32, 0, 54, 27);
	pX = posX;
	pY = posY;

	Life = 100;
	alive = true;
	inFight = false;
	inPath = false;
	direction = 0;
	test = 0;
}

Ennemy::~Ennemy()
{
	delete img;
}

void Ennemy::Do(float gameTime)
{
	pX = img->GetPosition().x;
	pY = img->GetPosition().y;
	
	if(checkAlive())
	{
		if(getInPath())
		{
			if(gameTime > 1)
				this->test++;

			if(direction == 1)
				img->Anim(gameTime, 100, -8);
			else
				img->Anim(gameTime, 100, 8);

			if(test > 3)
			{
				this->inPath = false;
				this->test = 0;
				this->direction = 0;
			}
		}
		else
		{
			img->Anim(gameTime, 100, 0);
		}

		img->Draw();
	}
}

float Ennemy::getPx()
{
	return pX;
}

float Ennemy::getPy()
{
	return pY;
}

int Ennemy::getLife()
{
	return Life;
}

void Ennemy::setLife(int life)
{
	Life = life;
}

void Ennemy::decLife(int life)
{
	Life -= life;
}

bool Ennemy::checkAlive()
{
	if(Life > 0)
		return true;
	else
		return false;
}

void Ennemy::setSprite(string path)
{
    img->Modify(path);
}

bool Ennemy::getInPath()
{
	return inPath;
}

void Ennemy::setInPath(bool b, int dir)
{
	this->inPath = b;
	this->direction = dir;
}