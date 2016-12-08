//
//  Square.hpp
//  getsudokuprojectfinal
//
//  Created by Aparna Gollakota on 12/7/16.
//  Copyright © 2016 Aparna Gollakota. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp
#include <list>

using namespace std;

class Square {
    
    list<int> available_values;
    
    int current_value;
    
public:
    
    Square();
    
    void reset();
    
    int getAvailableValue();
    
    int getCurrentValue();
    void setCurrentValue(int new_value);
    
};


#endif /* Square_h */
