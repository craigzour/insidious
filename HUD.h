#ifndef HUD_H
#define HUD_H

#include <iostream>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>

#include "Sprites.h"
#include "define.h"
#include "bloc.h"

using namespace std;
using namespace sf;

class Tour;

class HUD {
	public:
		HUD(RenderWindow &app);
        ~HUD();
		void draw();
		string int2string(int i);
		int GetScore();
		void SetScore(int);
		int GetMoney();
		void SetMoney(int);
		void AfficheEtat(Bloc* b);
		void drawRepareAndSell();
	    void manageEvent(Event event, Game* game);
		void addWave();
		void drawVictory();
	
	private:
        RenderWindow &app;
        Font imagineFont;
        
		Sprites *background;
        Sprites *imgEtat;
        Sprites *imgAchat;
		Sprites *repareBtn;
	    Sprites *sellBtn;

        Sprites *tour1;
        Sprites *tour2;
        Sprites *tour3;
        String infoTour1;
        String infoTour2;
        String infoTour3;
    
		int Score;
		int Money;
        string Type;
		String TypeString;
        String VieString;
    
        String MoneyString;
		String ScoreString;
		String WavesString;
		int wave;

		String VictoryString;
    
        Bloc* currentBloc;
};

#endif
