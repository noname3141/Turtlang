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

void penup(Turtle& turt);

void pendown(Turtle& turt);

void turn(Turtle& turt, int theta);

//parser logic

enum class TokenType{
	//commands
	FORWARD, BACK, TURN, PENUP, PENDOWN, REPEAT,
	//literals
	NUMBER,
	//delimiters
	LBRACKET, RBRACKET,
	//control
	END_OF_FILE, INVALID
};

typedef struct token {
	TokenType type;
	double val;
	int line;
} Token;

class Lexer{
private:
	std::string source;
	size_t start = 0; //start of the current lexeme being scanned
	size_t current = 0;//current read idx
	int line = 1;
	int col = 1;
public:
	explicit Lexer(std::string source) : source(std::move(source)){}; //to move the source into the source field the moment we pass it as an argument to lexer i.e. lexer(string);

	bool is_at_end(){
		return current >= source.size();
	};

	char advance(){
		if(is_at_end())return '\0';
		char c = source[current++];
		if(c== '\n'){
			line++;
			col = 1;
		}
		else{
			col++;
		}
		return c;
	};

	char peek(){
		if(is_at_end()) return '\0';
		return source[current];
	};
	
	char peek_next(){
		if(current + 1 >= source.length()) return '\0';
		return source[current + 1];
	};

	void skip_white_spaces_and_comments(){
		while(!is_at_end()){
			char c = peek();
			switch(c){
				case ' ':
				case '\r':
				case '\t':
				case '\n':
					advance();
					break;
				case '/':{
					char nx = peek_next(); 
					if(nx == '/'){
						while(!is_at_end() && peek() != '\n'){
							advance();
						}
					}
					else if(nx == '*'){
						advance();
						advance();
						while(!is_at_end() && !(peek() == '*' && peek_next() == '/')){
							advance();
						}
						if(!is_at_end()){
							advance();
							advance();
						}
					}
					else{
						return;
					}
					break;
					};
				default:
					return;
			}
		}
	}

};




#endif
