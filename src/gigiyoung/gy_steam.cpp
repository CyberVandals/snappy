/* gy_steam.cpp - Implemention file for steam object
 * By Gigi Young
 */

#include <stdlib.h>
#include "../../inc/gy_object.h"

//using namespace std;

// Default constructor 
Steam::Steam(QGraphicsItem *parent): AbstractObject(parent) {
    init();

    setPos(DEFAULT_POS_X, DEFAULT_POS_Y);

    timer->start(UPDATE_MS);
}

Steam::Steam(int x, int y, QGraphicsItem *parent): 
    AbstractObject(parent)
{
    init();

    setPos(x, y);

    timer->start(UPDATE_MS);
} 

void Steam::init() {

    time_active = 20 + rand() % 100;
    count = time_active;

    timer = new QTimer(this);
    graphics = new Graphics();
    sound = new SoundManager();

    graphics->load_steam(
        DEFAULT_STEAM_WIDTH, DEFAULT_STEAM_HEIGHT, this);

    // create timer for move slot
    connect( timer, SIGNAL(timeout()), this, SLOT(status()) );
}

void Steam::pause() {
    if(timer != NULL)
        timer->stop();
}

void Steam::resume() {
    if(timer != NULL)
        timer->start();
}

void Steam::status() {
    if(count > 0) {
        count--;
    }
    else {
        is_exploded = !is_exploded;
        count = time_active;
    }

    if(is_exploded) {
        // make object visible
        this->setVisible(true);
    }
    else {
        // make invisible
        this->setVisible(false);
    }


}
