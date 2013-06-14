#ifndef INSIDIOUS_H
#define INSIDIOUS_H

#include <SFML/Graphics.hpp>

#include "define.h"
#include "HUD.h"
#include "Sprites.h"
#include "game.h"
#include "ennemy.h"
#include "thread.h"

class Insidious
{
	public:
		Insidious();
        ~Insidious();
		void run();
		void drawMenu();
		sf::Event getEvent();
		void clear();
		void display();
		void updateTime();
		float getTime() const;
		void resetTime();
        bool in_vector(std::vector<int> d, int c);
	
	private:
		sf::RenderWindow m_app;
		sf::Event m_event;
		sf::Clock m_clock;

		Game *game;
		HUD *hud;

		float time;

		bool start;
		bool test;

		vector<Ennemy*> ennemyTab;
		vector<int> deads;

		void loadEnnemy();
		void ennemyType(int i, int rangeMin, int rangeMax);
};

#endif