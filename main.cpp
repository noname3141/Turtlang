#include "main.hpp"

float rad(int theta){
	return ((float)(PI/180.0)*(float)theta);
}

void penup(Turtle& turt){
	turt.pen_down = false;
}

void pendown(Turtle& turt){
	turt.pen_down = true;
}

std::pair<int, int> new_pos(Turtle& turt, int d){
	int dx = std::round(d*std::cos(rad(turt.theta)));
	int dy = std::round(d*std::sin(rad(turt.theta)));
	//int dx = d*std::cos(turt.theta);
	//int dy = d*std::sin(turt.theta);
	return {turt.pos.first + dx,turt.pos.second + dy};
}

void vislog(std::vector<std::pair<int, int>>& v, Turtle& turt, std::pair<int, int> np){
	if(np.first < 0 || np.first > BOUNDX || np.second < 0 || np.second > BOUNDY){
		std::cout << "out of bounds";
		return;
	}
	if(turt.pen_down)v.push_back(np);
	turt.pos.first = np.first;
	turt.pos.second = np.second;
	return;
}

void forward(std::vector<std::pair<int, int>>& v, Turtle& turt, int d){
	std::pair<int, int> np = new_pos(turt, d);
	vislog(v, turt, np);
	return;
}

void turn(Turtle& turt, int t){
	turt.theta += t;
	return;
}

int main(){
	Turtle myturt;
	std::cout << std::endl;
	std::vector<std::pair<int, int>> log;
	std::cout << myturt.pos.first << "," << myturt.pos.second << std::endl;
	forward(log, myturt, 10);
	std::cout << myturt.pos.first << "," << myturt.pos.second << std::endl;
	turn(myturt, 90);
	forward(log, myturt, 10);
	std::cout << myturt.pos.first << "," << myturt.pos.second << std::endl;
	return 0;
}
