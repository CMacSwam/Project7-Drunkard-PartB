/*
* Author: Chase McCluskey
* Date: 10/17/2024
* File: Lab Problem7A.1
* 
* Desription: Calculating expected and average distance traveled by 10,000 drunkards
*/


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

double drunkardlocation(int minutes, int drunkardnumber);
double expecteddistance(int minutes);

int main() {
	srand(static_cast<unsigned int> (time(0)));

	

	double totalsteps = 0;
	int userminutes = 0;
	

	cout << "Enter the number of minutes for each drunkard to stagger: ";
	cin >> userminutes;

	for (int i = 1; i <= 10000; i++) {
		totalsteps += drunkardlocation(userminutes, i);
		
	}

	double distance = expecteddistance(userminutes);

	cout << "Expected Distance: " << distance << endl;
	cout << "Average Distance: " << totalsteps / 10000;
	


}
double expecteddistance(int minutes) {
	double expecteddistance = sqrt((double)(minutes * 60) * (4+(4*sqrt(2)))/9);
	return expecteddistance;
}

double drunkardlocation(int minutes, int drunkardnumber) {

	int x = 0;
	int y = 0;

	for (int i = 1; i <= minutes * 60; i++) {

		int motion = rand() % 9 + 1;

		switch (motion) {
			//forward
		case 1: x = x, y = y + 1; break;
			//backward
		case 2: x = x, y = y - 1; break;
			//left
		case 3: x = x - 1; y = y; break;
			//right
		case 4: x = x + 1, y = y; break;
			//northeast
		case 5: x = x + 1, y = y + 1; break;
			//northwest
		case 6: x = x - 1, y = y + 1; break;
			//south east
		case 7: x = x + 1, y = y - 1; break;
			//southwest
		case 8: x = x - 1, y = y - 1; break;
			//no movement
		case 9: x = x, y = y; break;
		}
	}
	return sqrt((x * x) + (y * y));
}