#ifndef TOUR_H
#define TOUR_H

#include <SFML/Graphics.hpp>

#include "bloc.h"
#include "Sprites.h"

#include "define.h"
#include "ennemy.h"

class Ennemy;

using namespace sf;

class Tour : public Bloc {
	public:
		Tour(RenderWindow &app, float posX, float posY);
		~Tour();

		void Do(vector<Ennemy*> &v, float gameTime);

		float getPx();
		float getPy();
        int getPrice();
		bool getShot();
		void setShot(bool c);

	private:
		float pX, pY;
    
        int price;

		bool shot;
        int es;
    
		Sprites *mis;

		bool isIn(float x, float y);
};

#endif