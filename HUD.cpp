#include "HUD.h"

#include <iostream>

HUD::HUD(RenderWindow &app) : app(app)
{
	background = new Sprites(app, P_BARRE, 0.f, 576.f);
    imgEtat = new Sprites(app, P_ETAT, 250.f, 581.f);
    imgAchat = new Sprites(app, P_ACHAT, 570.f, 581.f);
	repareBtn = new Sprites(app, P_REPARE, 270.f, 640.f);
	sellBtn = new Sprites(app, P_SELL, 410.f, 640.f);
    
    tour1 = new Sprites(app, P_TOUR, 600.f, 610.f);
    tour1->setDragable(true);
    
    tour2 = new Sprites(app, P_TOUR, 770.f, 610.f);
    tour2->setDragable(true);
    
    tour3 = new Sprites(app, P_TOUR, 940.f, 610.f);
    tour3->setDragable(true);
    
    imagineFont.LoadFromFile(P_IMAGINE_FONT, 30);
    
    ScoreString = String("Score : 0", imagineFont, 25);
    MoneyString = String("Money : 300000", imagineFont, 25);
	WavesString = String("Wave : 1", imagineFont, 15);
	VictoryString = String("VICTORY", imagineFont, 100);
    
    VieString = String("Life : 0 ", imagineFont, 15);
    TypeString = String("Type :  ", imagineFont, 15);
    
    infoTour1 = String("Puissance : 30\nRayon : 80\nPrix : 1000$", imagineFont, 12);
    infoTour2 = String("Puissance : 60\nRayon : 130\nPrix : 5000$", imagineFont, 12);
    infoTour3 = String("Puissance : 100\nRayon : 200\nPrix : 10000$", imagineFont, 12);
    
	Score = 0;
    Money = 30000;
	wave = 0;
    
	VieString.SetPosition(320.f, 595.f);
	TypeString.SetPosition(320.f, 615.f);
    
    ScoreString.SetPosition(10.f, 590.f);
	MoneyString.SetPosition(10.f, 625.f);
	WavesString.SetPosition(1030.f, 5.f);
	VictoryString.SetPosition(320.f, 210.f);
    
    infoTour1.SetPosition(640.f, 606.f);
    infoTour2.SetPosition(810.f, 606.f);
    infoTour3.SetPosition(980.f, 606.f);

	currentBloc = 0;
}

HUD::~HUD()
{
    delete background;
    delete currentBloc;
    delete imgEtat;
    delete imgAchat;
}

void HUD::draw()
{
	background->Draw();
    imgEtat->Draw();
    imgAchat->Draw();
    
    tour1->getSprite().SetColor(sf::Color(255, 255, 255, Money < PRICE_TOUR1 ? 128 : 255));
    tour1->Draw();
    infoTour1.SetColor(sf::Color(255, 255, 255, Money < PRICE_TOUR1 ? 128 : 255));
    app.Draw(infoTour1);

    tour2->getSprite().SetColor(sf::Color(255, 255, 255, Money < PRICE_TOUR2 ? 128 : 255));
    tour2->Draw();
    infoTour2.SetColor(sf::Color(255, 255, 255, Money < PRICE_TOUR2 ? 128 : 255));
    app.Draw(infoTour2);
    
    tour3->getSprite().SetColor(sf::Color(255, 255, 255, Money < PRICE_TOUR3 ? 128 : 255));
    tour3->Draw();
    infoTour3.SetColor(sf::Color(255, 255, 255, Money < PRICE_TOUR3 ? 128 : 255));
    app.Draw(infoTour3);
    
	ScoreString.SetText("Score : " + this->int2string(Score));
	MoneyString.SetText("Money : " + this->int2string(Money) + " $");
	WavesString.SetText("Wave : " + this->int2string(wave) + " / 10");
	
    app.Draw(ScoreString);
	app.Draw(MoneyString);
	app.Draw(WavesString);
    
    if (currentBloc)
    {
        AfficheEtat(currentBloc);
    }
}

void HUD::AfficheEtat(Bloc* b)
{
    currentBloc = b;
    
	VieString.SetText("Life : " + this->int2string(currentBloc->GetVie()));
	app.Draw(VieString);
    
	TypeString.SetText("Type : " + currentBloc->GetType());
	app.Draw(TypeString);
    
	if (currentBloc->GetType() == "Caillou")
	{
		Sprites API = Sprites(app, P_CAILLOU , 270, 600);
		API.Draw();
		drawRepareAndSell();
	}
	if (currentBloc->GetType() == "Vide")
	{	
		Sprites API = Sprites(app, P_HERBE , 270, 600);
		API.Draw();
	}
    if (currentBloc->GetType() == "Tour")
	{
		Sprites API = Sprites(app, P_TOUR , 270, 600);
		API.Draw();
		drawRepareAndSell();
	}
}

void HUD::drawRepareAndSell()
{
    repareBtn->Draw();
    sellBtn->Draw();
}

void HUD::manageEvent(Event e, Game* game)
{
    if (Money >= PRICE_TOUR1)
    {
        if (tour1->manageEvent(e, game, this, 0))
        {
            Money -= PRICE_TOUR1;
            tour1->Position(600.f, 610.f);
        }
    }
    
    if (Money >= PRICE_TOUR2)
    {
        if (tour2->manageEvent(e, game, this, 1))
        {
            Money -= PRICE_TOUR2;
            tour2->Position(770.f, 610.f);
        }        
    }
    
    if (Money >= PRICE_TOUR3)
    {
        if (tour3->manageEvent(e, game, this, 2))
        {
            Money -= PRICE_TOUR3;
            tour3->Position(940.f, 610.f);
        }
    }
    
    if (e.Type == sf::Event::MouseButtonReleased)
	{
		if (repareBtn->hasHit((Vector2f((float)e.MouseButton.X, (float)e.MouseButton.Y))) && currentBloc != 0)
        {
            if (Money > 50)
            {
                if (currentBloc->GetVie() < 100)
                {
                    currentBloc->SetVie(currentBloc->GetVie() + 10);
                    Money -= 50;
                }
            }
        }
        else if (sellBtn->hasHit((Vector2f((float)e.MouseButton.X, (float)e.MouseButton.Y))) && currentBloc != 0)
        {
            Money += currentBloc->GetSellPrice();
            game->changeMap((int) currentBloc->getSprite().GetPosition().x / 32, (int) currentBloc->getSprite().GetPosition().y / 32, ',');
            currentBloc = 0;
        }
    }
}

string HUD::int2string (int i)
{
	ostringstream oss;
	oss << i;
	return oss.str();
}

int HUD::GetScore()
{
	return Score;
}

void HUD::SetScore(int newscore)
{
	Score = newscore;
}

int HUD::GetMoney()
{
	return Money;
}

void HUD::SetMoney(int newmoney)
{
	Money = newmoney;
}

void HUD::addWave()
{
	wave++;
}

void HUD::drawVictory()
{
	app.Draw(VictoryString);
}

