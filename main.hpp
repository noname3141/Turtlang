// file with all the defs for the turtlang
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <vector>

#define BOUNDX 4000
#define BOUNDY 1000

#define PI 3.14159265358

class Animal{
public:
	std::string name;
	Animal(std::string n) : name(n){
		std::cout << "parent constructor called";
		std::cout << "\nAnimal name is " << name;
	}
};

class Turtle : public Animal{
public:
	std::pair<int, int> pos = {0, 0};
	int theta = 0;
	bool pen_down;
	Turtle() : Animal("Turtle"){
		std::cout << "\nderived constructor called\n";
		std::cout << name << " is at pos x : " << pos.first << ", y : " << pos.second;
	};
};

float rad(int theta);//i have to convert theta to rad to pass in through the sin and cos fns
std::pair<int, int> new_pos(Turtle& turt, int distance);
void vislog(std::vector<std::pair<int, int>>& v, Turtle& turt, std::pair<int, int> np);
void forward(std::vector<std::pair<int, int>>& v, Turtle& turt,int distance);
void turn(Turtle& turt, int theta);

#endif
