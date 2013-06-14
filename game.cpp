#include "game.h"

#include <iostream>

Game::Game(RenderWindow &app, vector<Ennemy*> &enn) : app(app), ennemy(enn)
{	

}

Game::~Game()
{
    for (int x = 0; x < 18; x++) {
		for (int y = 0; y < 36; y++) {
			delete m_map[y][x];
		}	
	}
}

void Game::loadBackground()
{
	ifstream fichier(P_MAP, ios::in);
	
	string ligne;
	int x = 0;
	while(getline(fichier, ligne))
	{
		for (int y = 0; y < 36; y++) {
			switch (ligne[y]) {
				case '#':
					m_map[y][x] = new Vide(app, (float) y*32, (float) x*32);
					break;
				case ',':
					m_map[y][x] = new Vide(app, (float) y*32, (float) x*32);
					break;
				case 'o':
					m_map[y][x] = new Caillou(app, (float) y*32, (float) x*32);
					break;
				case 't':
					m_map[y][x] = new Tour(app, (float) y*32, (float) x*32);
					break;
			}
		}
		x++;
	}
	
	fichier.close();	
}

void Game::run(vector<Ennemy*> &v, float gameTime)
{
	this->displayBackground();

	for (int x = 0; x < 18; x++) {
		for (int y = 0; y < 36; y++) {
			m_map[y][x]->Do(v, gameTime);
		}	
	}
	
	/* mettre ici le deroulement du jeu */
}

void Game::displayBackground()
{
	for (int x = 0; x < 18; x++) {
		for (int y = 0; y < 36; y++) {
			m_map[y][x]->draw();
		}	
	}
}

void Game::changeMap(int x, int y, char choix, int typeOfTour)
{
    if ((m_map[x][y]->GetType() == "Vide" && 't' == choix) || ',' == choix)
    {
        delete m_map[x][y];
        
        switch (choix) {
            case 'o':
                m_map[x][y] = new Caillou(app, (float)x*32, (float)y*32);
                break;
            case ',':
                m_map[x][y] = new Vide(app, (float) x*32, (float) y*32);
                break;
            case 't':
                m_map[x][y] = new Tour(app, (float) x*32, (float) y*32);
                switch (typeOfTour) {
                    case 0:
                        m_map[x][y]->setStrenght(30);
                        m_map[x][y]->setRayon(80);
						m_map[x][y]->SetSellPrice(500);
                        m_map[x][y]->setColor(Color(51, 204, 0, 255));
                        //m_map[x][y]->setSprite...
                        break;
                    case 1:
                        m_map[x][y]->setStrenght(60);
                        m_map[x][y]->setRayon(130);
						m_map[x][y]->SetSellPrice(2500);
                        m_map[x][y]->setColor(Color(255, 204, 0, 255));                        
                        //m_map[x][y]->setSprite...
                        break;
                    case 2:
                        m_map[x][y]->setStrenght(100);
                        m_map[x][y]->setRayon(200); 
						m_map[x][y]->SetSellPrice(5000);
                        m_map[x][y]->setColor(Color(255, 0, 0, 255));
                        //m_map[x][y]->setSprite...
                        break;
                    default:
                        break;
                }
				this->pathFinding(x, y);
                break;
            default:
                break;
        }
    }
}

void Game::event(Event event, Game* &game, HUD* &hud)
{
    for (int x = 0; x < 18; x++) {
		for (int y = 0; y < 36; y++) {
			m_map[y][x]->manageEvent(event, game, hud);
		}	
	}
}

void Game::pathFinding(int x, int y)
{
	int y1 = (y * 32) - 40;
	int y2 = (y * 32) + 40;
	int y3 = y2 - ((y2 - y1) / 2);

	for (int i = 0; i < (signed)ennemy.size(); i++)
	{
		if((ennemy[i]->getPy() > y1) && (ennemy[i]->getPy() < y2))
		{
			if(ennemy[i]->getPy() < y3)
				ennemy[i]->setInPath(true, 1);
			else
				ennemy[i]->setInPath(true, 2);
		}
	}
}
