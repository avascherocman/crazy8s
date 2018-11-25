
/* Ava Scherocman
Crazy 8s Project
11/24/18
*/

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
#include <string.h>
#include <iomanip>

int main()
{
  sf::RenderWindow win(sf::VideoMode(1000, 1000), "Crazy Eights");
  while (win.isOpen()) {
    sf::Event event;

    while (win.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        win.close();
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {

      }
      win.clear(sf::Color::Black);

    }
  }
  return 0;
}

/*sf::Texture i;
i.loadFromFile("C:\\Users\\InterlinkAdmin\\Pictures\\jenga.jpg");
sf::Sprite s;
s.setTexture(i);*/
