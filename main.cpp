#include <iostream>
#include <random>

#include "shape.h"
#include "transform.h"

int main() {
	std::multimap<char, std::vector<int>> coord;
	coord.emplace('x', std::vector<int> {2, 4, 6, 8, 10, 12, 14, 16});
	coord.emplace('y', std::vector<int> {3, 5, 7, 9, 11, 13, 15, 17});
	coord.emplace('z', std::vector<int> {18, 19, 20, 21, 22, 23, 24, 25});

	Shape cube(Shape::TypeOne::cube, coord);
	std::cout << "Площадь куба: " << cube.square << "\nОбъем куба: " << cube.volume << std::endl;

	Shape cylinder(Shape::TypeTwo::cylinder, coord, 15, 30);
	std::cout << "\nПлощадь цилиндра: " << cylinder.square << "\nОбъем цилиндра: " << cylinder.volume << std::endl;

	transform cube_t(cube);
	cube_t.scale(2);

	std::cout << "\nПлощадь куба после скалирования: " << cube.square << "\nОбъем куба после скалирования: " << cube.volume << std::endl;

	return 0;
}