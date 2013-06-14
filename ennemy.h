#ifndef ENNEMY_H
#define ENNEMY_H

#include <SFML/Graphics.hpp>

#include "define.h"
#include "Sprites.h"
#include "HUD.h"

using namespace sf;

class Ennemy {
	public:
		Ennemy(RenderWindow &app, float posX, float posY);
		~Ennemy();
        
		void Do(float gameTime);
		float getPx();
		float getPy();
		int getLife();
		void setLife(int life);
		void decLife(int life);
		bool checkAlive();
        void setSprite(string path);
		bool getInPath();
		void setInPath(bool b, int dir);
	
	private:
		Sprites *img;

		float pX, pY;
		int Life;

		bool alive;
		bool inFight;
		bool inPath;
		int direction;
		float test;
};

#endif