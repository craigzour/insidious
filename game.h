#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <SFML/Graphics.hpp>

#include "define.h"
#include "bloc.h"
#include "vide.h"
#include "caillou.h"
#include "tour.h"

using namespace sf;
using namespace std;

class HUD;
class Ennemy;

class Game 
{
	public:
		Game(RenderWindow &app, vector<Ennemy*> &enn);
        ~Game();
		void loadBackground();
		void displayBackground();
		void run(vector<Ennemy*> &v, float gameTime);
		void changeMap(int x, int y, char choix, int typeOfTour = 0);
    
        void event(Event event, Game* &game, HUD* &hud);

	protected:
		RenderWindow &app;
		Bloc *m_map[36][18];

		vector<Ennemy*> &ennemy;

		void pathFinding(int x, int y);
};

#endif