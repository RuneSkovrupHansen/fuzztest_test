#include "character.hpp"

    int Character::get_level() {
        return level;
    }


    int Character::get_health() {
        return level * 10;
    }

    bool Character::set_level(int level) {
        if (level>0) {
            this->level = level;
            return true;
        }
        return false;
    }