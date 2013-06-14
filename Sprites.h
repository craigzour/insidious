#ifndef SPRITES_H
#define SPRITES_H

#include <string>

#include <SFML/Graphics.hpp>

#include "define.h"

#include "game.h"

#include "tour.h"
#include "ennemy.h"

#include "HUD.h"

using namespace sf;
using namespace std;

class Tour;
class Ennemy;

class Sprites
{
	public:
		Sprites(RenderWindow &app);
		Sprites(const Sprites& Copy);
		Sprites(RenderWindow &app, string path, float x, float y);
		Sprites(RenderWindow &app, string path, float x, float y, int x1, int y1, int x2, int y2);
		Sprites(RenderWindow &app, string path, float x, float y, float centerX, float centerY, float rotation);
		Sprites(RenderWindow &app, string path, float x, float y, float centerX, float centerY, float rotation, float scaleX, float scaleY);
		Sprites(RenderWindow &app, string path, float x, float y, int x1, int y1, int x2, int y2, float centerX, float centerY, float rotation, float scaleX, float scaleY);
		~Sprites();

		void initVar();
	
		Sprite& getSprite();
		float Width() const;
		float Height() const;
		sf::Vector2f GetPosition() const;
		sf::Vector2f Center() const;
		float GetRotation() const;
		bool isDragable();
		bool isDD();
		
		void setDragable(bool d);
		void setDD(bool d);
		void Position(float x, float y);
		void Translate(float x, float y);	
		void Rotate(float rotation);
		void FlipVertically(bool state);
		void FlipHorizontally(bool state);
		
		void Draw() const;
		void Modify(std::string path);
		void Resize(float sizeX, float sizeY);
		void Cut(int x1, int y1, int x2, int y2);

		bool rotAnim(float gameTime, float duringTime, float rot);

		bool Anim(float gameTime, float range, float ver);

		void shot(float gameTime, Tour &t, Ennemy &e);

		bool hasHit(Vector2f const & point);
		bool manageEvent(Event event, Game* game, HUD* hud, int typeOfTour = 0);
		
	private:
		Image img;
		Sprite spr;
		RenderWindow &app;

		bool inAnim, isDrag, isdd;
		float mov, mov2, endTime;
		string path;
		float x, y;
		int part;
};

#endif