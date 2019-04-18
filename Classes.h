#include <windows.h>
#include <string>

using namespace std;

bool creatureAlive = false;

class Food {
public:
	int kalories;
	int proteins;
	int fats;
	int carbohydrates;
	Food(int kal, int prot, int f, int car) {
		kalories = kal;
		proteins = prot;
		fats = f;
		carbohydrates = car;
	}
};

class Date {
public:
	int m;
	int d;
	int h;
	int s;
	Date(Date& date, int day, int hour, int minute, int second) {
		date.d = day;
		date.h = hour;
		date.m = minute;
		date.s = second;
	}
};

class Creature {
public:
	string name;
	int age = 0;
	int hp = 100;
	int nutrition = 50;
	int water = 50;
	int mood = 5;
	int dirt = 0;
	int height = 10;
	int weight = 10;
	int animalCounter;
	int daysSinceCreated = 0;
	SYSTEMTIME timeCreated;
	Creature(int counter, SYSTEMTIME time, string nickname ) {
		if (creatureAlive) {
			cout << "I dont know how u attempt to create new creature while u have one, but it's prohibited. So this is error message(";
			throw("Creation error message(");
		}
		name = nickname;
		animalCounter = counter;
		timeCreated = time;
		
	}
	void liveTact() {
		liveLevel();
		starvation();
		thirst();
	}
	void feedWithFood(Food food) {
		nutrition += food.kalories / 100;
	}
	void feed() {
		nutrition += 5;
	}
	void giveWater() {
		water += 5;
	}
	void displayAttributes() {
		cout << "Health level: " << hp << endl << "Nutrition level: " << nutrition << endl << "Water level: " << water << endl << "Mood level: " << mood;
	}
	void showStatus() {
		cout << "Ur animal age: " << age << endl << "Height: " << height << endl << "Weight: " << weight << endl;
	}

private:
	void liveLevel() {
		// food
		if (nutrition >= 80 && nutrition <= 100) {
			mood++;
			if (mood >= 10)
				mood = 10;
		}
		else if (nutrition <= 40){
			hp--;
			mood--;
		}
		else if (nutrition > 100) {
			nutrition = 100;
			cout << "Ur animal doesn't want too eat yet";
		}
		// water
		if (water >= 80 && water <= 100) {
			mood++;
			if (mood >= 10)
				mood = 10;
		}
		else if (water <= 40) {
			hp--;
			mood--;
		}
		else if (water > 100) {
			water = 100;
			cout << "Ur animal doesn't want too drink yet";
		}
		// health
		if (hp <= 30) {
			mood -= 2;
		}
		if (mood <= 0) {
			mood = 0;
			hp -= 5;
			cout << endl <<  "Ur animal in very bad state! Care better!";
		}
		if (hp <= 0) {
			hp = 0;
			creatureAlive = false;
		}
		if (mood >= 10) {
			mood = 10;
			int rnd = rand() % 6;
			switch (rnd) {
			case 0:
				//nothing happened
				break;
			case 1:
				//nothing happened too
				break;
			case 2:
				cout << endl  << name + " so happy right now!!!";
				break;
			case 3:
				cout << endl << name + " glad too see u!!";
				break;
			case 4:
				cout << endl  << name + " so happy right now!!!";
				break;
			case 5:
				cout << endl << name + "'s eyes glow with happiness!!!";
				break;
			}
		}
		if (mood <= 3) {
			int rnd = rand() % 6;
			switch (rnd) {
			case 0:
				//nothing happened
				break;
			case 1:
				//nothing happened too
				break;
			case 2:
				cout << endl << name + " pritty sad(";
				break;
			case 3:
				cout << endl << name + " has a bad mood :'(";
				break;
			case 4:
				cout << endl << name + "'s very upset";
				break;
			case 5:
				cout << endl << name + " wants to die((((";
				break;
			}
		}
		if (hp <= 30) {
			int rnd = rand() % 6;
			switch (rnd) {
			case 0:
				//nothing happened
				break;
			case 1:
				//nothing happened too
				break;
			case 2:
				cout << endl << name + " looks ill";
				break;
			case 3:
				cout << endl << "It's look like your animal in bad condition. U should take care of ur pet better!";
				break;
			case 4:
				cout << endl << name + "'s coughing";
				break;
			case 5:
				cout << endl << name + " wants to die((((";
				break;
			}
		}
	}
	void starvation() {
		nutrition--;
	}
	void thirst() {
		water -= 2;
	}

};