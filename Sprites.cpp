#include "Sprites.h"

#include <iostream>

/**************************CONSTRUCTORS******************************/


Sprites::Sprites(RenderWindow &app) : app(app) {}
Sprites::~Sprites()
{
}

Sprites::Sprites(const Sprites& Copy) : img(Copy.img), spr(Copy.spr), app(Copy.app)
{
	img.LoadFromFile(Copy.path);
	img.SetSmooth(false);
	
	spr.SetImage(this->img);
	spr.SetPosition(Copy.x, Copy.y);
	
	initVar();
	
	this->path = path;
	this->x = x;
	this->y = y;
}

Sprites::Sprites(RenderWindow &app, string path, float x, float y) : app(app)
{
	img.LoadFromFile(path);
	img.SetSmooth(false);
	
	spr.SetImage(this->img);
	spr.SetPosition(x, y);
	
	initVar();
	
	this->path = path;
	this->x = x;
	this->y = y;
}

Sprites::Sprites(RenderWindow &app, string path, float x, float y, int x1, int y1, int x2, int y2) : app(app)
{
	img.LoadFromFile(path);
	img.SetSmooth(false);
	
	spr.SetImage(this->img);
	spr.SetPosition(x, y);
	spr.SetSubRect(IntRect(x1, y1, x2, y2));
	
	initVar();
	
	this->path = path;
	this->x = x;
	this->y = y;
}

Sprites::Sprites(RenderWindow &app, string path, float x, float y, float centerX, float centerY, float rotation) : app(app)
{
	img.LoadFromFile(path);
	img.SetSmooth(false);
	
	spr.SetImage(this->img);
	spr.SetPosition(x, y);
	spr.SetCenter(centerX, centerY);
	spr.SetRotation(rotation);
	
	initVar();
	
	this->path = path;
	this->x = x;
	this->y = y;
}

Sprites::Sprites(RenderWindow &app, string path, float x, float y, float centerX, float centerY, float rotation, float scaleX, float scaleY) : app(app)
{
	img.LoadFromFile(path);
	img.SetSmooth(false);

	spr.SetImage(this->img);
	spr.SetPosition(x, y);
	spr.SetCenter(centerX, centerY);
	spr.SetRotation(rotation);
	spr.SetScale(scaleX, scaleY);
	
	initVar();
	
	this->path = path;
	this->x = x;
	this->y = y;
}

Sprites::Sprites(RenderWindow &app, string path, float x, float y, int x1, int y1, int x2, int y2, float centerX, float centerY, float rotation, float scaleX, float scaleY) : app(app)
{
	img.LoadFromFile(path);
	img.SetSmooth(false);

	spr.SetImage(this->img);
	spr.SetPosition(x, y);
	spr.SetSubRect(IntRect(x1, y1, x2, y2));
	spr.SetCenter(centerX, centerY);
	spr.SetRotation(rotation);
	spr.SetScale(scaleX, scaleY);
	
	initVar();
	
	this->path = path;
	this->x = x;
	this->y = y;
}

void Sprites::initVar()
{
	inAnim = false;
	isDrag = false;
	isdd = false;
	mov = 0;
	mov2 = 0;
	endTime = 0;
	part = 0;
}

/***************************GETTERS******************************/


Sprite& Sprites::getSprite()
{
	return spr;
}

float Sprites::Width() const
{
	return spr.GetSize().x;
}

float Sprites::Height() const
{
	return spr.GetSize().y;
}

Vector2f Sprites::GetPosition() const
{
	return spr.GetPosition();
}

Vector2f Sprites::Center() const
{
	return spr.GetCenter();
}

float Sprites::GetRotation() const
{
	return spr.GetRotation();
}

bool Sprites::isDragable()
{
	return isDrag;
}

bool Sprites::isDD()
{
	return isdd;
}

/***************************SETTERS******************************/

void Sprites::setDragable(bool d)
{
	isDrag = d;
}

void Sprites::setDD(bool d)
{
	if (isDrag)
	{
		isdd = d;
		spr.SetColor(sf::Color(255, 255, 255, d ? 128 : 255));
	}
}

void Sprites::Position(float x, float y)
{
	spr.SetPosition(x, y);
}

void Sprites::Translate(float x, float y)
{
	spr.Move(x, y);
}

void Sprites::Rotate(float rotation)
{
	spr.Rotate(rotation);
}

void Sprites::FlipVertically(bool state)
{
	spr.FlipX(state);
}

void Sprites::FlipHorizontally(bool state)
{
	spr.FlipY(state);
}


/***************************METHODS******************************/


void Sprites::Draw() const
{
	app.Draw(spr);
}

void Sprites::Modify(string path)
{
	img.LoadFromFile(path);
	img.SetSmooth(false);

	spr.SetImage(this->img);
}

void Sprites::Resize(float sizeX, float sizeY)
{
	spr.Resize(sizeX, sizeY);
}

void Sprites::Cut(int x1, int y1, int x2, int y2)
{
	spr.SetSubRect(IntRect(x1, y1, x2, y2));
}

bool Sprites::rotAnim(float gameTime, float duringTime, float rot)
{
	if (!inAnim)
	{
		mov = rot / duringTime;
		endTime = 0;
		inAnim = true;
	}

	if (gameTime > 1)
	{
		Rotate(mov);
		endTime += 1;
	}

	if (endTime >= duringTime)
	{
		inAnim = false;

		return true;
	}
	
	return false;
}

bool Sprites::Anim(float gameTime, float range, float ver)
{
	if(!inAnim)
	{
		part = 0;
		endTime = 0;
		mov = 8;
		inAnim = true;
	}

	if(gameTime > 1)
	{
		if(part == 0)
			Cut(32, 0, 54, 27);
		if(part == 1)
			Cut(55, 0, 77, 27);
		if(part == 2)
			Cut(78, 0, 100, 28);
		if(part == 3)
			Cut(101, 0, 123, 27);
		if(part == 4)
			Cut(125, 0, 146, 27);
		if(part == 5)
			Cut(147, 0, 169, 27);

		Translate(mov, ver);
		endTime += 8;
		part++;
	}

	if(part > 5)
		part = 0;

	if(endTime >= range)
	{
		//Cut(0, 0, 31, 27);
		inAnim = false;
		return true;
	}

	return false;
}

void Sprites::shot(float gameTime, Tour &t, Ennemy &e)
{
	if(e.checkAlive())
	{
		Shape line = Shape::Line(t.getPx() + 15, t.getPy(), e.getPx() + 15, e.getPy() + 15, 1, t.getColor(), 0, Color(255,255,255));
		app.Draw(line);

		if(gameTime > 1)
		{
			e.decLife(t.getStrenght());
		}
	}
}

bool Sprites::hasHit(sf::Vector2f const & point)
{
    sf::Vector2f pointT = spr.TransformToLocal(point);
	
    if (pointT.x <= 0)
        return false;
    else if (pointT.x >= spr.GetSubRect().GetWidth())
        return false;
    else if (pointT.y <= 0)
        return false;
    else if (pointT.y >= spr.GetSubRect().GetHeight())
        return false;
	
    return true;
}

bool Sprites::manageEvent(Event e, Game* game, HUD* hud, int typeOfTour)
{
	if (e.Type == sf::Event::MouseButtonPressed)
	{

        if (hasHit(Vector2f((float)e.MouseButton.X, (float)e.MouseButton.Y)))
		{
			setDD(true);
			
            return false;
		}
	}
	
	if (e.Type == sf::Event::MouseButtonReleased)
	{
		if (hasHit(Vector2f((float)e.MouseButton.X + 1, (float)e.MouseButton.Y + 1)))
		{
			if (e.MouseButton.X > 0 && e.MouseButton.X < W_WIDTH && e.MouseButton.Y > 0 && e.MouseButton.Y < W_HEIGHT - 106) {
		
				game->changeMap((int)e.MouseButton.X/32, (int)e.MouseButton.Y/32, 't', typeOfTour);
				
				setDD(false);
				
				return true;
			}
		}
	}
	
	if (e.Type == sf::Event::MouseMoved)
	{
		if (isDD())
		{
			Position((float)e.MouseMove.X, (float)e.MouseMove.Y);
			
			return false;
		}
	}	
	
	return false;
}
