#include<string>
#include<cstring>
#include<iostream>


using namespace std;

int mode(int h)
{
	char ui_mode;
	cout << "Choose a mode: B for Basic B or I for Insaenz" << endl;
	cin >> ui_mode;

	ui_mode = tolower(ui_mode);
	if (ui_mode != 'b' && ui_mode != 'i') {
		cout << "You did not enter a correct mode!  Choose a mode: B for Basic B or I for Insaenz" << endl;
		cin >> ui_mode;
	}
	if (ui_mode == 'b') h = 10000;
	else if (ui_mode == 'i') h = 2;
	return h;
}
