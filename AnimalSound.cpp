#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal 
{
public:
	virtual void makeSound() = 0;
};

class Dog : public Animal
{
public:
	void makeSound() {
		cout << "°­¾ÆÁö°¡ ¿Ð¿Ð ÇÏ°í Â¢½À´Ï´Ù." << endl;
	}
};
class Cat : public Animal
{
public:
	void makeSound() {
		cout << "°í¾çÀÌ°¡ ¾ß¿Ë ÇÏ°í ¿ó´Ï´Ù." << endl;
	}
};
class Cow : public Animal
{
public:
	void makeSound() {
		cout << "¼Ò°¡ À½¸Þ~ÇÏ°í ¿ó´Ï´Ù." << endl;
	}
};
class Zoo 
{
private:
	Animal* animals[10];
	int num = 0;
public:
	void addAnimal(Animal* animal) {
		animals[num] = animal; 
		num++;
	}
	void performActions() {
		for (int i = 0; i < 10; i++) {
			animals[i]->makeSound();
		}
	}

	~Zoo() {
		for (int i = 0; i < 10; i++) {
			delete animals[i];
		}
	}

};

Animal* createRandomAnimal() {
	int rannum = rand() % 3;
	cout << rannum;

	switch (rannum)
	{
	case 0:
		return new Dog();
		break;
	case 1:
		return new Cat();
		break;
	case 2:
		return new Cow();
		break;
	}
}


int main() {
	Animal* myAnimal[3];
	Zoo* myZoo =new Zoo();
	srand(time(NULL));

	myAnimal[0] = new Dog();
	myAnimal[1] = new Cat();
	myAnimal[2] = new Cow();

	for (int i = 0; i < 3; i++) {
		myAnimal[i]->makeSound();
	}

	for (int i = 0; i < 10; i++) {
		myZoo -> addAnimal(createRandomAnimal());
	}

	myZoo->performActions();


	return 0;
}