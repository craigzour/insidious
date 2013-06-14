#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"
#include "Sprites.h"
#include "ennemy.h"

class thread : public sf::Thread
{
public:
	thread(RenderWindow &app, vector<Ennemy*> &enn);
private :
    virtual void Run();
	vector<Ennemy*> &ennemy;
	RenderWindow &app;
};