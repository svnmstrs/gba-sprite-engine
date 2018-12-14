//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_bios.h>
#include <cmath>
#include <libgba-sprite-engine/math.h>
#include "bullet.h"


void Bullet::setDestination(VECTOR destination) {
    auto currentPos = sprite->getPos();
    this->dest = destination;

    this->coords = Math::bresenhamLineBetween(currentPos, destination);
}

void Bullet::tick() {
    if(coords.empty()) {
        return;
    }

    sprite->moveTo(coords.front());
    coords.pop_front();
}
