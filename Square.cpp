#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <iostream>
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

int Square::getAvailableValue(){

	if (available_values.empty()){
		return -1;
	}

	int return_val = available_values.front();
	available_values.pop_front();

	return return_val;

}

int Square::getCurrentValue(){
	return current_value;
}

void Square::setCurrentValue(int new_value){
	current_value = new_value;
}

void Square::reset(){
	setCurrentValue(-1);

	// intializing the available values list
	for (int x = 0; x < 9; x++){
		available_values.push_front(x + 1);
	}

	for (int x = 0; x < 1000; x++){
		int rand_one = rand() % 3;
		if (rand_one < (rand() % 6)){
			available_values.push_front(available_values.back());
			available_values.pop_back();
		}
		else{
			available_values.push_back(available_values.front());
			available_values.pop_front();
		}
	}

}

Square::Square(void){

	reset();

}
