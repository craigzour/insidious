#ifndef DEFINE_H
#define DEFINE_H

#include <iostream>
#include <string>
#include <vector>

#define W_WIDTH				1152
#define W_HEIGHT			680
#define W_TITLE				"~~ Insidious ~~"
#define W_STYLE				sf::Style::Titlebar | sf::Style::Close
#define W_DEPTHBITS			24
#define W_STENCILBITS		8
#define W_ALIASING			0
#define W_FPS				125
#define W_VSYNC				false

#ifdef __APPLE__
    #define PATH                "../../"
#endif

#ifndef __APPLE__
    #define PATH                ""
#endif


#define P_ICO				PATH "Images/tour2.png"
#define P_LOAD              PATH "Images/load.png"
#define P_MAP				PATH "Maps/1.lvl"
#define P_START				PATH "Images/start.png"

#define P_IMAGINE_FONT      PATH "fonts/imagine_font.ttf"

#define P_HERBE				PATH "Images/herbe2.png"
#define P_CAILLOU			PATH "Images/caillou2.png"
#define P_TOUR				PATH "Images/tour2.png"

#define P_BARRE				PATH "Images/barre.png"
#define P_ETAT				PATH "Images/fondetat.png"
#define P_ACHAT				PATH "Images/fondachat.png"
#define P_REPARE            PATH "Images/repare.png"
#define P_SELL              PATH "Images/sell.png"

#define SPR_SOLDAT1         PATH "Images/soldat.png"
#define SPR_SOLDAT2         PATH "Images/soldat2.png"
#define SPR_SOLDAT3         PATH "Images/soldat3.png"

#define SPR_TANK            PATH "Images/tank.png"
#define SPR_MISSILE         PATH "Images/missile.png"

#define PRICE_TOUR1         1000
#define PRICE_TOUR2         5000
#define PRICE_TOUR3         10000


#endif