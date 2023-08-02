#include <iostream>

#include "shape.h"
#include "transform.h"

int main() {
	Shape cube(2, 6, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 4, 2, 3, 4, 5, 6);
	std::cout << "Площадь: " << cube.square << "\nОбъем: " << cube.volume << std::endl;

	transform cube_t(cube);
	cube_t.scale(2);

	std::cout << "Площадь: " << cube.square << "\nОбъем: " << cube.volume << std::endl;

	return 0;
}