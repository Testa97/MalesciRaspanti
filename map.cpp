//
// Created by francesco on 09/01/18.
//

#include "map.h"
#include <iostream>


int Menu::renderMap()
{
    int x,y;
    enum Direction {Down, Left, Right, Up};

    sf::Vector2i source(1, Down);

    float frameCounter = 0, switchFrame = 100, frameSpeed = 500;





    // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 704), "Tilemap");



    window.setKeyRepeatEnabled(false);

    sf::Texture pTexture;
    sf::Sprite playerImage;
    sf::Clock clock;

    bool updateFrame = true;


    if(!pTexture.loadFromFile("/home/alessandro/CLionProjects/untitled1/prigioniero.png"))
        std::cout << "Error could not load player image" << std::endl;

    playerImage.setTexture(pTexture);
    playerImage.setPosition(416, 160);


    // define the level with an array of tile indices
    const int level[] =
            {
                    59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,
                    63,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	63,
                    63,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	63,
                    63,	97,	97,	28,	20,	20,	20,	44,	20,	20,	20,	44,	20,	20,	20,	44,	20,	20,	20,	58,	58,	20,	20,	20,	44,	20,	20,	20,	44,	20,	20,	20,	44,	20,	20,	20,	32,	97,	97,	63,
                    63,	97,	97,	24,	38,	2,	43,	24,	38,	2,	43,	24,	38,	2,	43,	24,	0,	0,	0,	0,	0,	0,	0,	0,	24,	38,	2,	43,	24,	38,	2,	43,	24,	38,	2,	43,	24,	97,	97,	63,
                    63,	97,	97,	24,	42,	2,	50,	24,	42,	2,	50,	24,	42,	2,	50,	24,	0,	0,	0,	0,	0,	0,	0,	0,	24,	42,	2,	50,	24,	42,	2,	50,	24,	42,	2,	50,	24,	97,	97,	63,
                    63,	97,	97,	24,	22,	58,	22,	24,	22,	58,	22,	24,	22,	58,	22,	40,	0,	0,	0,	0,	0,	0,	0,	0,	36,	22,	58,	22,	24,	22,	58,	22,	24,	22,	58,	22,	24,	97,	97,	63,
                    63,	97,	97,	24,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	24,	97,	97,	63,
                    63,	97,	97,	24,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	24,	97,	97,	63,
                    63,	97,	97,	24,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	24,	97,	97,	63,
                    63,	97,	97,	24,	20,	20,	20,	20,	20,	20,	58,	20,	20,	20,	20,	20,	20,	32,	0,	0,	0,	0,	28,	20,	20,	58,	20,	20,	44,	20,	20,	20,	58,	20,	20,	20,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	24,	0,	0,	0,	0,	24,	8,	8,	8,	8,	8,	24,	2,	2,	2,	2,	2,	2,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	54,	54,	54,	4,	4,	4,	4,	4,	54,	54,	54,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	91,	2,	91,	2,	91,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	2,	2,	2,	2,	2,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	4,	4,	4,	4,	4,	4,	4,	4,	54,	54,	54,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	91,	2,	91,	2,	91,	2,	24,	97,	97,	63,
                    63,	97,	97,	56,	20,	95,	99,	99,	99,	32,	4,	4,	4,	4,	4,	4,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	2,	2,	2,	2,	2,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	46,	4,	4,	4,	4,	24,	4,	4,	4,	54,	54,	54,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	91,	2,	91,	2,	91,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	4,	4,	4,	4,	58,	4,	4,	4,	4,	4,	4,	4,	24,	0,	0,	0,	0,	24,	8,	8,	8,	8,	8,	24,	2,	2,	2,	2,	2,	2,	2,	24,	97,	97,	63,
                    63,	97,	97,	36,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	52,	20,	58,	58,	20,	52,	20,	20,	20,	20,	20,	52,	20,	20,	20,	20,	20,	20,	20,	40,	97,	97,	63,
                    63,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	63,
                    63,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	63,
                    59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,

            };

    const int level2[] =
            {
                    59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,
                    63,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	63,
                    63,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	63,
                    63,	97,	97,	28,	20,	20,	20,	44,	20,	20,	20,	44,	20,	20,	20,	44,	20,	20,	20,	58,	58,	20,	20,	20,	44,	20,	20,	20,	44,	20,	20,	20,	44,	20,	20,	20,	32,	97,	97,	63,
                    63,	97,	97,	24,	38,	2,	43,	24,	38,	2,	43,	24,	38,	2,	43,	24,	0,	0,	0,	0,	0,	0,	0,	0,	24,	38,	2,	43,	24,	38,	2,	43,	24,	38,	2,	43,	24,	97,	97,	63,
                    63,	97,	97,	24,	42,	2,	50,	24,	42,	2,	50,	24,	42,	2,	50,	24,	0,	0,	0,	0,	0,	0,	0,	0,	24,	42,	2,	50,	24,	42,	2,	50,	24,	42,	2,	50,	24,	97,	97,	63,
                    63,	97,	97,	24,	22,	58,	22,	24,	22,	58,	22,	24,	22,	58,	22,	40,	0,	0,	0,	0,	0,	0,	0,	0,	36,	22,	58,	22,	24,	22,	58,	22,	24,	22,	58,	22,	24,	97,	97,	63,
                    63,	97,	97,	24,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	24,	97,	97,	63,
                    63,	97,	97,	24,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	24,	97,	97,	63,
                    63,	97,	97,	24,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	24,	97,	97,	63,
                    63,	97,	97,	24,	20,	20,	20,	20,	20,	20,	58,	20,	20,	20,	20,	20,	20,	32,	0,	0,	0,	0,	28,	20,	20,	58,	20,	20,	44,	20,	20,	20,	58,	20,	20,	20,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	24,	0,	0,	0,	0,	24,	8,	8,	8,	8,	8,	24,	2,	2,	2,	2,	2,	2,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	54,	54,	54,	4,	4,	4,	4,	4,	54,	54,	54,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	91,	2,	91,	2,	91,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	2,	2,	2,	2,	2,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	4,	4,	4,	4,	4,	4,	4,	4,	54,	54,	54,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	91,	2,	91,	2,	91,	2,	24,	97,	97,	63,
                    63,	97,	97,	56,	20,	95,	99,	99,	99,	32,	4,	4,	4,	4,	4,	4,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	2,	2,	2,	2,	2,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	46,	4,	4,	4,	4,	24,	4,	4,	4,	54,	54,	54,	4,	24,	0,	0,	0,	0,	24,	8,	64,	24,	64,	8,	24,	2,	91,	2,	91,	2,	91,	2,	24,	97,	97,	63,
                    63,	97,	97,	24,	4,	4,	4,	4,	4,	58,	4,	4,	4,	4,	4,	4,	4,	24,	0,	0,	0,	0,	24,	8,	8,	8,	8,	8,	24,	2,	2,	2,	2,	2,	2,	2,	24,	97,	97,	63,
                    63,	97,	97,	36,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	20,	52,	20,	58,	58,	20,	52,	20,	20,	20,	20,	20,	52,	20,	20,	20,	20,	20,	20,	20,	40,	97,	97,	63,
                    63,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	63,
                    63,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	97,	63,
                    59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,	59,

            };

    // create the tilemap from the level definition

    TileMap map;
    if (!map.load("/home/alessandro/CLionProjects/menu/tilesetmod2.png", sf::Vector2u(32, 32), level, 40, 22))
        return -1;
    TileMap map2;
    if (!map.load("/home/alessandro/CLionProjects/menu/tilesetmod3.png", sf::Vector2u(32, 32), level2, 40, 22))
        return -1;
    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {

                case sf::Event::KeyReleased:
                    switch (event.key.code) //qui ci saranno tutti i casi in cui il giocatore preme un tasto per interagire(tipo tasto inventario?)
                    {
                        case sf::Keyboard::Escape:
                            //invece della chiusura, ci sarà un menù di pausa che fa scegliere se riprendere oppure no(?)
                            window.close();
                            break;
                        case sf::Keyboard::E:
                            //aprire l'inventario
                            map.openInventory();
                    }
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code){
                        case sf::Keyboard::Up:
                            source.y = Up;
                            playerImage.move(0,-2);
                            break;
                        case sf::Keyboard::Down:
                            source.y = Down;
                            playerImage.move(0,2);
                            break;
                        case sf::Keyboard::Right:
                            source.y = Right;
                            playerImage.move(2,0);
                            break;
                        case sf::Keyboard::Left:
                            source.y = Left;
                            playerImage.move(-2,0);
                            break;

                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
            }




            frameCounter = (updateFrame) ? frameCounter + frameSpeed * clock.restart().asSeconds() : 0;

            if(frameCounter >= switchFrame)
            {
                frameCounter = 0;
                source.x++;
                if (source.x * 50 >= pTexture.getSize().x)
                    source.x = 0;
            }
            playerImage.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

        }

        // draw the map
        window.clear();
        window.draw(map);
        window.draw(map2);
        window.draw(playerImage);
        window.display();
    }


}