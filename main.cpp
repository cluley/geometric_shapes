#include <iostream>
#include <random>

#include "shape.h"
#include "transform.h"

int main() {
	std::map<char, std::vector<int>> coord;
	coord.emplace('x', std::vector<int> {2, 4, 6, 8, 10, 12, 14, 16});
	coord.emplace('y', std::vector<int> {3, 5, 7, 9, 11, 13, 15, 17});
	coord.emplace('z', std::vector<int> {18, 19, 20, 21, 22, 23, 24, 25});

	Shape cube(3, coord);
	std::cout << "Площадь куба: " << cube.calc_square() << "\nОбъем куба: " << cube.calc_volume() << std::endl;

	Shape cylinder(5, coord, 15, 30);
	std::cout << "\nПлощадь цилиндра: " << cylinder.calc_square() << "\nОбъем цилиндра: " << cylinder.calc_volume() << std::endl;

	transform cube_t(cube);
	cube_t.scale(2);

	std::cout << "\nПлощадь куба после скалирования: " << cube.calc_square() << "\nОбъем куба после скалирования: " << cube.calc_volume() << std::endl;

	return 0;
}