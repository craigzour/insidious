#include "insidious.h"

Insidious::Insidious()
{
	/*
	 
	*/
	m_app.Create(sf::VideoMode(W_WIDTH, W_HEIGHT),
				 W_TITLE,
				 W_STYLE,
				 sf::WindowSettings::WindowSettings	(W_DEPTHBITS, W_STENCILBITS, W_ALIASING));
	m_app.SetFramerateLimit(W_FPS);
	m_app.UseVerticalSync(W_VSYNC);
	
	sf::Image icon;
	icon.LoadFromFile(P_ICO);
	m_app.SetIcon(32, 32, icon.GetPixelsPtr());
    
	game = new Game(m_app, ennemyTab);
	hud = new HUD(m_app);

	start = false;
	test = false;

	resetTime();
}

Insidious::~Insidious()
{
    delete game;
    delete hud;
}

void Insidious::run()
{	
	Sprites *load = new Sprites(m_app, P_LOAD, 0, 0);

	load->Draw();

	display();

	game->loadBackground();
	loadEnnemy();

	Sprites *butStart = new Sprites(m_app, P_START, 290, 610);

	//thread *th = new thread(m_app, ennemyTab);

	int checkWave = 50;
    
	while (m_app.IsOpened())
    {
		/*if(start)
			th->Launch();*/

		updateTime();

        while (m_app.GetEvent(m_event))
        {
            if (m_event.Type == sf::Event::Closed)
                m_app.Close();

			if (butStart->hasHit((Vector2f((float)m_event.MouseButton.X, (float)m_event.MouseButton.Y))) && !start)
			{
				start = true;
				hud->addWave();
			}
			
			if(start)
				game->event(m_event, game, hud);

			hud->manageEvent(m_event, game);
        }

		clear();

		game->run(ennemyTab, getTime());
		hud->draw();

		if(!ennemyTab.empty())
		{
			for(int i = 0; i < (signed)ennemyTab.size(); i++)
			{
				if(start)
					ennemyTab[i]->Do(getTime());

				if (!ennemyTab[i]->checkAlive() && !in_vector(deads, i+1)) 
				{
					hud->SetScore(hud->GetScore() + 10);
					hud->SetMoney(hud->GetMoney() + 50);
					deads.push_back(i+1);
				}
			}
		}

		for(int i = checkWave; i < (checkWave + 50); i++)
		{
			if(ennemyTab[i]->getPx() > 0.f)
			{
				hud->addWave();
				checkWave += 50;
				break;
			}
		}

		if(!ennemyTab[499]->checkAlive())
		{
			hud->drawVictory();
		}

		if(!start)
			butStart->Draw();

		display();	

		if( getTime() > 1 )
			resetTime();
    }
	
}

void Insidious::drawMenu()
{
	/*
	 programmer ici le menu, lance directement le jeu actuellement
	*/
	
}

void Insidious::clear()
{
	m_app.Clear();
}

void Insidious::display()
{
	m_app.Display();
}

sf::Event Insidious::getEvent()
{
	return m_event;
}

void Insidious::updateTime()
{
	this->time += this->m_clock.GetElapsedTime();
}

float Insidious::getTime() const
{
	return this->time;
}

void Insidious::resetTime()
{
	time = 0;
	this->m_clock.Reset();
}

bool Insidious::in_vector(std::vector<int> d, int c)
{
    for (int i = 0; i < (signed)d.size(); i++)
    {
        if (d[i] == c)
        {
            return true;
        }
    }
    return false;
}

void Insidious::loadEnnemy()
{
	ennemyTab.resize(500);
	deads.resize(ennemyTab.size());

	for (int i = 0; i < (signed)ennemyTab.size(); i++)
	{
		if(i >= 0 && i < 50)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(0, 500) * -1), (float)sf::Randomizer::Random(100, 320));
			ennemyType(i, 0, 0);
		}
		else if(i >= 50 && i < 100)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(1200, 1700) * -1), (float)sf::Randomizer::Random(90, 340));
			ennemyType(i, 0, 0);
		}
		else if(i >= 100 && i < 150)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(2500, 3000) * -1), (float)sf::Randomizer::Random(80, 360));
			ennemyType(i, 0, 1);
		}
		else if(i >= 150 && i < 200)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(3500, 4000) * -1), (float)sf::Randomizer::Random(70, 380));
			ennemyType(i, 1, 1);
		}
		else if(i >= 200 && i < 250)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(4500, 5000) * -1), (float)sf::Randomizer::Random(60, 400));
			ennemyType(i, 1, 1);
		}
		else if(i >= 250 && i < 300)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(5500, 6000) * -1), (float)sf::Randomizer::Random(50, 420));
			ennemyType(i, 1, 2);
		}
		else if(i >= 300 && i < 350)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(6500, 7000) * -1), (float)sf::Randomizer::Random(40, 440));
			ennemyType(i, 1, 2);
		}
		else if(i >= 350 && i < 400)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(7500, 8000) * -1), (float)sf::Randomizer::Random(30, 460));
			ennemyType(i, 1, 2);
		}
		else if(i >= 400 && i < 450)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(8500, 9000) * -1), (float)sf::Randomizer::Random(20, 480));
			ennemyType(i, 1, 2);
		}
		else if(i >= 450 && i < 500)
		{
			ennemyTab[i] = new Ennemy(m_app, ((float)sf::Randomizer::Random(9500, 10000) * -1), (float)sf::Randomizer::Random(10, 500));
			ennemyType(i, 2, 2);
		}
    }
}

void Insidious::ennemyType(int i, int rangeMin, int rangeMax)
{
	switch(sf::Randomizer::Random(rangeMin, rangeMax))
    {
		case 0:
			ennemyTab[i]->setSprite(SPR_SOLDAT1);
            ennemyTab[i]->setLife(200);
        break;
        case 1:
            ennemyTab[i]->setSprite(SPR_SOLDAT2);
            ennemyTab[i]->setLife(500);
        break;
        case 2:
            ennemyTab[i]->setSprite(SPR_SOLDAT3);
            ennemyTab[i]->setLife(1000);
        break;
	}
}