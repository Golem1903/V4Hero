
#include "RhythmGUI.h"
#include <cmath>
RhythmGUI::RhythmGUI()
{
    //ctor
     r_rhythm.setSize(sf::Vector2f(100,100));
    r_rhythm.setFillColor(sf::Color::White);

    r_fever.setSize(sf::Vector2f(100,10));
    r_fever.setFillColor(sf::Color::Red);

    r_fever_meter.setSize(sf::Vector2f(100,10));
    r_fever_meter.setFillColor(sf::Color::Yellow);
}

void RhythmGUI::Initialise(Config &config, std::map<int,bool> &keymap)
{

}


///TO BE PORTED TO AN EXTERNAL CLASS
void RhythmGUI::doVisuals(sf::RenderWindow& window,int bgm_cycle,sf::Clock *rhythmClock,int combo,float *flicker,float fps,std::vector<Drum> *drums)
{
    auto lastView = window.getView();

    window.setView(window.getDefaultView());

    /**
    clock250 - full white
    clock400 - faded white
    clock
    */

    int v_cycle_mode = abs(floor((bgm_cycle)/4) - 1);
    int v_cycle = (bgm_cycle)%4 + 1;

    int rhythmAlpha = 250 - (rhythmClock->getElapsedTime().asMilliseconds() / 2);

    ///Visuals
    if(true)
    {
        ///Calculate the ratio for other window sizes (default is 1280x720)
        float ratio_X = window.getSize().x / float(1280);
        float ratio_Y = window.getSize().y / float(720);
        float ratio_universal = (window.getSize().x * window.getSize().y) / (float(1280) * float(720));

        /// Beat frame
        if((combo <= 1) or ((combo > 1) and (combo < 11) and (v_cycle_mode == 0)))
        {
            r_rhythm.setFillColor(sf::Color(0,0,0,0));
            r_rhythm.setOutlineThickness(-ceil(3 * ratio_universal));
            r_rhythm.setOutlineColor(sf::Color(255,255,255,rhythmAlpha));
            r_rhythm.setSize(sf::Vector2f((1280 * ratio_X) - (24 * ratio_X), (720 * ratio_Y) - (24 * ratio_Y)));
            r_rhythm.setPosition(12*ratio_X,12*ratio_Y);

            r_rhythm2.setOutlineColor(sf::Color(0,0,0,0));
        }
        else if((combo > 1) and (v_cycle_mode == 1))
        {
            r_rhythm.setFillColor(sf::Color(0,0,0,0));
            r_rhythm.setOutlineThickness(-ceil(2 * ratio_universal));
            r_rhythm.setOutlineColor(sf::Color(64,64,64,rhythmAlpha));
            r_rhythm.setSize(sf::Vector2f((1280 * ratio_X) - (20 * ratio_X), (720 * ratio_Y) - (20 * ratio_Y)));
            r_rhythm.setPosition(10*ratio_X,10*ratio_Y);

            r_rhythm2.setFillColor(sf::Color(0,0,0,0));
            r_rhythm2.setOutlineThickness(-ceil(2 * ratio_universal));
            r_rhythm2.setOutlineColor(sf::Color(64,64,64,rhythmAlpha));
            r_rhythm2.setSize(sf::Vector2f((1280 * ratio_X) - (30 * ratio_X), (720 * ratio_Y) - (30 * ratio_Y)));
            r_rhythm2.setPosition(15*ratio_X,15*ratio_Y);

            if(v_cycle == 4)
            {
                if(floor(*flicker) == 0)
                {
                    r_rhythm.setOutlineColor(sf::Color(64,64,64,rhythmAlpha));
                    r_rhythm2.setOutlineColor(sf::Color(64,64,64,rhythmAlpha));
                }
                else if(floor(*flicker) == 1)
                {
                    r_rhythm.setOutlineColor(sf::Color(220,220,220,rhythmAlpha));
                    r_rhythm2.setOutlineColor(sf::Color(220,220,220,rhythmAlpha));
                }

                *flicker += float(1) / fps * 30;

                if(*flicker >= 2)
                    *flicker = 0;
            }
        }
        else if((combo >= 11) and (v_cycle_mode == 0))
        {
            r_rhythm.setFillColor(sf::Color(0,0,0,0));
            r_rhythm.setOutlineThickness(-ceil(7 * ratio_universal));

            r_rhythm.setSize(sf::Vector2f((1280 * ratio_X) - (20 * ratio_X), (720 * ratio_Y) - (20 * ratio_Y)));
            r_rhythm.setPosition(10*ratio_X,10*ratio_Y);

            r_rhythm2.setOutlineColor(sf::Color(0,0,0,0));

            int flick = floor(*flicker);

            switch(flick)
            {
                case 0:
                r_rhythm.setOutlineColor(sf::Color(255,255,0,rhythmAlpha));
                break;

                case 1:
                r_rhythm.setOutlineColor(sf::Color(255,255,255,rhythmAlpha));
                break;

                case 2:
                r_rhythm.setOutlineColor(sf::Color(0,255,255,rhythmAlpha));
                break;

                case 3:
                r_rhythm.setOutlineColor(sf::Color(0,255,0,rhythmAlpha));
                break;
            }

            *flicker += float(1) / fps * 30;

            if(*flicker >= 4)
                *flicker = 0;
        }

        /// Fever meter - now with 16 segments!
        int feverMeterWidth = 10*(combo-12);
        if(feverMeterWidth > 160)
        {
            feverMeterWidth = 160;
        }

        float sizeMod = rhythmAlpha/float(80);

        r_fever.setSize(sf::Vector2f(160+sizeMod*2,10+sizeMod*2));
        r_fever_meter.setSize(sf::Vector2f(feverMeterWidth+sizeMod*2,10+sizeMod*2));

        r_fever.setPosition(50*ratio_X-sizeMod,50*ratio_Y-sizeMod);
        r_fever_meter.setPosition(50*ratio_X-sizeMod,50*ratio_Y-sizeMod);
    }

    window.draw(r_rhythm);
    window.draw(r_rhythm2);
    window.draw(r_fever);

    if(combo > 12)
    {
        window.draw(r_fever_meter);
    }

    for(int i=0; i<drums->size(); i++)
    {
        (*drums)[i].fps = fps;
        (*drums)[i].Draw(window);

        if((*drums)[i].alpha <= 0)
        {
            drums->erase(drums->begin() + i);
        }
    }

    window.setView(lastView);
}

//void RhythmGUI::Update(sf::RenderWindow &window, float fps){

//}

RhythmGUI::~RhythmGUI()
{
    //dtor
}
