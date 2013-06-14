#ifndef CAILLOU_H
#define CAILLOU_H

#include <SFML/Graphics.hpp>
#include "bloc.h"

#include "define.h"

using namespace sf;

class Ennemy;

class Caillou : public Bloc {
	public:
		Caillou(RenderWindow &app, float posX, float posY);

		void Do(vector<Ennemy*> &v, float gameTime);
};

#endif