#include <iostream>
#include "Classes.h"
#include <conio.h>


using namespace std;

int counter = 0;

long timePass(SYSTEMTIME time) {
	SYSTEMTIME now;
	GetSystemTime(&now);
	return now.wSecond - time.wSecond + 60 * (now.wMinute - time.wMinute) + 3600 * (now.wHour - time.wHour);
}

void gameDisplay(Creature creature) {
	cout << "Ur animal " + creature.name << endl;
	creature.displayAttributes();
	cout << endl << "Pres keys to perform actions:" << endl;
	cout << " - 'f' for feed ur animal" << endl << " - 'w' for give water" << endl;
	cout << " - 's' for status of ur animal" << endl << " - 'k' for kill ur animal" << endl;
}

int input(Creature creature) {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'f':
			return 1;
			break;
		case 'w':
			return 2;
			break;
		case 's':
			return 3;
			break;
		case 'k':
			creatureAlive = false;
			break;
		}
		
	}
	return 0;
}



Creature createAnimal(SYSTEMTIME date) {
	string name;
	cout << "Give it a name: ";
	cin >> name;
	Creature animal = Creature(counter, date, name);
	counter++;
	creatureAlive = true;
	cout << endl << "ITS ALIVE!!!!!!!" << endl;
	return animal;
	//cout << "Your creature " << name << " is alive!!!";
}

Creature firstStart() {
	SYSTEMTIME timeNow;
	GetSystemTime(&timeNow);
	cout << "Ok, fellow, its game about pet ur own animal(but its only alfa, so dont be strict)" << endl;
	cout << "First of all u should create ur pet"<< endl;
	Creature animal = createAnimal(timeNow);
	animal.daysSinceCreated++;
	return animal;
	//cout << now.h << ":" << now.m << ":" << now.s << endl;
}

Creature start() {
	SYSTEMTIME timeNow;
	GetSystemTime(&timeNow);
	Creature animal = createAnimal(timeNow);
	animal.daysSinceCreated++;
	return animal;
}


void liveProcess(Creature creature) {
	SYSTEMTIME timeStart;
	SYSTEMTIME time;
	int commandN = 0;
	timeStart = creature.timeCreated;
	time = timeStart;
	while (creatureAlive) {
		commandN = input(creature);
		switch (commandN)
		{
		case 1:
			creature.feed();
			system("cls");
			GetSystemTime(&time);
			gameDisplay(creature);
			cout << endl << "U feet ur animal" << endl;
			break;
		case 2:
			creature.giveWater();
			system("cls");
			GetSystemTime(&time);
			gameDisplay(creature);
			cout << endl << "U gave water to ur animal" << endl;
			break;
		case 3:
			system("cls");
			GetSystemTime(&time);
			gameDisplay(creature);
			creature.showStatus();
			break;
		}
		if (timePass(time) > 5) {
			system("cls");
			GetSystemTime(&time);
			gameDisplay(creature);
			creature.liveTact();
		}
		commandN = 0;
	}
}

void retry() {
	char answer;
	cout << "Your animal are dead!" << endl << "Would u like to try again?(press 'r' for retry) ";
	cin >> answer;
	if (answer == 'R' || answer == 'r') {
		Creature animal = start();
		liveProcess(animal);
		retry();
	}

}

int main() {
	Creature animal = firstStart();
	liveProcess(animal);
	retry();
	system("pause");
	return 0;
}
