#include <iostream>
#include<SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Juego.h"
#include "cScreen.h"
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    cScreen menu;
    menu.inicializa();
    menu.accion();
    //_getch();
    return 0;
}
