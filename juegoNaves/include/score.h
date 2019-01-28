#ifndef SCORE_H
#define SCORE_H
#include "SFML/Graphics.hpp"
class score
{
    public:
        unsigned int puntoPlayer;
        score();
        void show(sf::RenderWindow &ventana);
        void addPointPlayer();
        void addPointIa();
        virtual ~score();
    private:
        sf::Font *fuente1;
        sf::Text *textPlayer;
        sf::Text textIA;

        unsigned int pointIA;
};

#endif // SCORE_H
