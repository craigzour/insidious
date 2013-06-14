#include "bloc.h"
#include "Sprites.h"
#include "game.h"
#include "HUD.h"

Bloc::Bloc(RenderWindow &app, string path, float posX, float posY) : app(app)
{
	Vie = 100;
	img = new Sprites(app, path, posX, posY);
}

Bloc::~Bloc()
{
	delete img;
}

void Bloc::Do(vector<Ennemy*> &v, float gameTime) 
{
	
}

void Bloc::draw()
{
	img->Draw();
}

Sprites& Bloc::getSprite()
{
	return *img;
}

int Bloc::GetVie()
{
	return Vie;
}

void Bloc::SetVie(int newvie)
{
	Vie = newvie;

	if(Vie < 0)
		Vie = 0;
	else if(Vie > 100)
		Vie = 100;
}

int Bloc::getStrenght()
{
	return strenght;
}

void Bloc::setStrenght(int s)
{
    strenght = s;
}

int Bloc::getRayon()
{
	return rayon;
}

void Bloc::setRayon(int s)
{
    rayon = s;
}


string Bloc::GetType()
{
	return Type;
}

int Bloc::GetSellPrice()
{
	return sellPrice;
}

void Bloc::SetSellPrice(int p)
{
	this->sellPrice = p;
}

void Bloc::setColor(sf::Color c)
{
    rayonColor = c;
}

Color Bloc::getColor()
{
    return rayonColor;
}

void Bloc::setSprite(string path)
{
    img->Modify(path);
}

bool Bloc::manageEvent(Event e, Game* &game, HUD* &hud)
{
	if (e.Type == sf::Event::MouseButtonPressed)
	{
		if (hasHit(Vector2f((float)e.MouseButton.X, (float)e.MouseButton.Y)))
		{
            hud->AfficheEtat(this);
						
			return false;
		}
	}
	
	return false;
}

bool Bloc::hasHit(sf::Vector2f const & point)
{
    sf::Vector2f pointT = img->getSprite().TransformToLocal(point);
	
    if (pointT.x <= 0)
        return false;
    else if (pointT.x >= img->getSprite().GetSubRect().GetWidth())
        return false;
    else if (pointT.y <= 0)
        return false;
    else if (pointT.y >= img->getSprite().GetSubRect().GetHeight())
        return false;
	
    return true;
}

