#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <iostream>
#include <list>
#ifndef Square_h
#define Square_h
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

#endif 