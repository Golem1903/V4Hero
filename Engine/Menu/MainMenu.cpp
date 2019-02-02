#include "MainMenu.h"

MainMenu::MainMenu()
{
    //ctor
    f_font.loadFromFile("resources/fonts/patapon.ttf");
    t_title.setFont(f_font);
    t_title.setCharacterSize(112);
    //t_title.setColor(sf::Color::White);
    t_title.setFillColor(sf::Color::White);
    t_title.setString("PATAFOUR");
    t_title.setOrigin(t_title.getGlobalBounds().width/2,t_title.getGlobalBounds().height/2);

    t_pressToContinue.setFont(f_font);
    t_pressToContinue.setCharacterSize(32);
    //t_pressToContinue.setColor(sf::Color::White);
    t_pressToContinue.setFillColor(sf::Color::White);
    t_pressToContinue.setString("Press any key to continue...");
    t_pressToContinue.setOrigin(t_pressToContinue.getGlobalBounds().width/2,t_pressToContinue.getGlobalBounds().height/2);

    mm_bigBox.setSize(sf::Vector2f(100,10));
    mm_bigBox.setFillColor(sf::Color(80,0,180));

    mm_smallerBox.setSize(sf::Vector2f(100,10));
    mm_smallerBox.setFillColor(sf::Color::Red);

    mm_titleBox.setSize(sf::Vector2f(100,10));
    mm_titleBox.setFillColor(sf::Color::Red);
}
MainMenu::KeyPressedEvent(sf::Event event){
    // do something here;
}
MainMenu::Update(sf::RenderWindow &window, float fps)
{


    mm_bigBox.setSize(sf::Vector2f(window.getSize().x,window.getSize().y-200));
    //mm_smallerBox.setSize(sf::Vector2f(100,10));
    //mm_titleBox.setSize(sf::Vector2f(100,10));

    mm_bigBox.setPosition(0,85);
    //mm_smallerBox.setPosition(100,10);
    //mm_titleBox.setPosition(100,10);


    window.draw(mm_bigBox);
    //window.draw(mm_smallerBox);
    //window.draw(mm_titleBox);

    t_title.setPosition(window.getSize().x/2,200);
    window.draw(t_title);

    t_pressToContinue.setPosition(window.getSize().x/2,300);
    window.draw(t_pressToContinue);



}

MainMenu::~MainMenu()
{
    //dtor
}