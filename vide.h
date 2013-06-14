#ifndef VIDE_H
#define VIDE_H

#include <SFML/Graphics.hpp>
#include "bloc.h"

#include "define.h"

using namespace sf;

class Ennemy;

class Vide : public Bloc {
	public:
		Vide(RenderWindow &app, float posX, float posY);

		void Do(vector<Ennemy*> &v, float gameTime);
};

#endif