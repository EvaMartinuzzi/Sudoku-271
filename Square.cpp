//
//  Square.cpp
//  getsudokuprojectfinal
//
//  Created by Aparna Gollakota on 12/7/16.
//  Copyright © 2016 Aparna Gollakota. All rights reserved.
//

#include "Square.h"
#include <iostream>

using namespace std;

int Square::getAvailableValue() {
    
    if (available_values.empty()) {
        return -1;
    }
    
    int return_val = available_values.front();
    available_values.pop_front();
    
    return return_val;
    
}

int Square::getCurrentValue() {
    return current_value;
}

void Square::setCurrentValue(int new_value) {
    current_value = new_value;
}

void Square::reset() {
    setCurrentValue(-1);
    
    // intializing the available values list
    for (int x = 0; x < 9; x++) {
        available_values.push_front(x + 1);
    }
    
    for (int x = 0; x < 1000; x++) {
        int rand_one = rand() % 3;
        if (rand_one < (rand() % 6)) {
            available_values.push_front(available_values.back());
            available_values.pop_back();
        }
        else {
            available_values.push_back(available_values.front());
            available_values.pop_front();
        }
    }
    
}



Square::Square(void) {
    
    reset();
    
}

