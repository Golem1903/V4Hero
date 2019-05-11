#ifndef RYTHMGUI_H
#define RYTHMGUI_H

#include <SFML/Graphics.hpp>
#include "../Config.h"

#include "Drum.h"
class RhythmGUI
{
    public:


           /// Visuals ///
        sf::RectangleShape r_rhythm;
        sf::RectangleShape r_rhythm2;

        sf::RectangleShape r_fever;
        sf::RectangleShape r_fever_meter;





        void Initialise(Config &config, std::map<int,bool> &keymap);
        void doVisuals(sf::RenderWindow& window,int bgm_cycle,sf::Clock *rhythmClock,int combo,float *flicker,float fps,std::vector<Drum> *drums);
        void Draw(sf::RenderWindow& window);
        RhythmGUI();
        ~RhythmGUI();
};


#endif // CAMERA_H
