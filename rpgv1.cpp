// Simple RPG.cpp 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;


class stats {
	public: // this can be accessed from anywhere
		void setHealth(int v) { health = v; }
		void setStrength(int v) { strength = v; }
		void setSpeed(int v) { speed = v; }
		void setStamina(int v) { stamina = v; }
		void setAwareness(int v) { awareness = v; }
		void setIntellect(int v) { intellect = v; }
		void setMana(int v) { mana = v; }

		int getHealth() { return health; }
		int getStrength() { return strength; }
		int getSpeed() { return speed; }
		int getStamina() { return stamina; }
		int getAwareness() { return awareness; }
		int getIntellect() { return intellect; }
		int getMana() { return mana; }

    stats() {
      srand(time(NULL));
    }

    float attack() {
			float v;
			v = ((strength * .5) + (stamina * .2) + (speed * .1));
			return v;
		}

		float defend() {
			float v;
			v = ((awareness * .5) + (strength * .2) + (stamina * .2) + (speed * .1));;
			return v;
		}

		float maxHP() {
			float v;
			v = ((health * 10) * (strength * .3));;
			return v;
		}

	protected: // this can be accessed the local or derived class
		int rollDice(int lowest, int highest) {
			int v; //declare a local variable to hold the value
			v = rand() % ((highest - lowest) + 1) + lowest; //create a random number from the lowest to the highest
			return v; //return the random value
		}


	private: // this can be accessed by the local class only 
		int health ;
		int strength;
		int speed;
		int stamina;
		int awareness;
		int intellect;
		int mana;

};


class persona {
	public:
		string getName() { return name; }
		void setName(string v) { name = v; }
    
	protected:
	
	private:
		string name;
};


class creature: public stats, public persona {
	public:
		int getWorldX() { return worldx; }
		int getWorldY() { return worldy; }
		int getDMG() { return dmgtaken; }

		bool isAlive() {
			bool alive = true;
			if (dmgtaken >= maxHP()) {
				alive = false;
			}
			return alive;
		}

		void setWorldX(int v) { worldx = v; }
		void setWorldY(int v) { worldy = v; }
		void addDMG(int v) { dmgtaken = dmgtaken + v; }

		creature() {
			//srand(time(NULL)); //set the random seed 
			setHealth(rollDice(1,10));
			setStrength(rollDice(1, 10));
			setSpeed(rollDice(1, 10));
			setStamina(rollDice(1, 10));
			setAwareness(rollDice(1, 10));
			setIntellect(rollDice(1, 10));
			setMana(rollDice(1, 10));

			setWorldX(rollDice(1, 30));
			setWorldY(rollDice(1, 30));

		}

	protected:
	private:
		int worldx;
		int worldy;
		int dmgtaken;
};


int main()
{
	creature Player, Mod1;

	cout << "Welcome to our\n";
	cout << "Role Playing Game" << endl;

	Player.setName("Ethan");
	//Player.setHealth(10);
	//Player.setStamina(23);

	cout << "Name: " << Player.getName() << ", Health: " << Player.getHealth() << ",  Stamina: " << Player.getStamina() << endl;
	cout << "Attack Value: " << Player.attack() << endl;
	cout << "Defend Value: " << Player.defend() << endl;
	cout << "Maximum HP Value: " << Player.maxHP() << endl;

	cout << "Current Damage Taken: " << Player.getDMG() << endl;

	Player.addDMG(20);
	Player.addDMG(15);
	Player.addDMG(34);

	cout << "Now the current Damage Taken: " << Player.getDMG() << endl;

	if (Player.isAlive()) {
		cout << "Yeah, you are still alive" << endl;
	}
	else {
		cout << "Aww, you are dead" << endl;
	}

    return 0;
}
