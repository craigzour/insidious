#ifndef BLOC_H
#define BLOC_H

#include <SFML/Graphics.hpp>

#include "define.h"

using namespace sf;
using namespace std;

class Sprites;
class HUD;
class Game;
class Ennemy;

class Bloc
{
	public:
		Bloc(RenderWindow &app, string path, float posX, float posY);
        ~Bloc();
		virtual void Do(vector<Ennemy*> &v, float gameTime)=0;
		void draw();
		Sprites& getSprite();
		int GetVie();
		int GetSellPrice();
		void SetSellPrice(int p);
		void SetVie(int);
		string GetType();
        int getStrenght();
        void setStrenght(int s);
        int getRayon();
        void setRayon(int r);
        void setSprite(string path);
    
        void setColor(Color c);
        Color getColor();
    
        bool hasHit(Vector2f const & point);
        bool manageEvent(Event event, Game* &game, HUD* &hud);
    
	protected:
		Sprites *img;
		RenderWindow &app;
		int Vie;
		string Type;
		int sellPrice;
        int strenght;
        int rayon;
    
        Color rayonColor;
};

#endif
