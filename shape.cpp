#define _USE_MATH_DEFINES

#include"shape.h"
#include <cmath>

double line::square(coordinates& coord) {
	return 0;
}

double line::volume(coordinates& coord) {
	return 0;
}

double sqr::square(coordinates& coord) {
	int a = abs(coord.find('x')->second[0] - coord.find('x')->second[1]);
	int b = abs(coord.find('y')->second[0] - coord.find('y')->second[1]);

	return a * b;
}

double sqr::volume(coordinates& coord) {
	return 0;
}

double cube::square(coordinates& coord) {
	int a = abs(coord.find('x')->second[0] - coord.find('x')->second[1]);
	int b = abs(coord.find('y')->second[0] - coord.find('y')->second[1]);
	int c = abs(coord.find('z')->second[0] - coord.find('z')->second[1]);

	return 2 * a * b + 2 * a * c + 2 * b * c;
}

double cube::volume(coordinates& coord) {
	int a = abs(coord.find('x')->second[0] - coord.find('x')->second[1]);
	int b = abs(coord.find('y')->second[0] - coord.find('y')->second[1]);
	int c = abs(coord.find('z')->second[0] - coord.find('z')->second[1]);

	return a * b * c;
}

double circle::square(coordinates& coord) {
	return M_PI * radius * radius;;
}

double circle::volume(coordinates& coord) {
	return 0;
}

double cylinder::square(coordinates& coord) {
	return M_PI * radius * radius + 2 * radius * height;
}

double cylinder::volume(coordinates& coord) {
	return M_PI * radius * radius * height;
}

Shape::Shape(int _type, coordinates& _coord) {
	type = static_cast<Shape::TypeOne>(_type);
	coord = _coord;

	calc_info();
}

Shape::Shape(int _type, coordinates& _coord, double R, double H){
	type = static_cast<Shape::TypeTwo>(_type);
	coord = _coord;

	calc_info(R, H);
}

void Shape::calc_info(const double R, const double H) {
	if (std::holds_alternative<TypeOne>(type))
	{
		switch (std::get<TypeOne>(type))
		{
		case TypeOne::line:
			info = std::make_shared<line>();
			break;
		case TypeOne::sqr:
			info = std::make_shared<sqr>();
			break;
		case TypeOne::cube:
			info = std::make_shared<cube>();
			break;
		default:
			break;
		}
	}
	else if (std::holds_alternative<TypeTwo>(type))
	{
		switch (std::get<TypeTwo>(type))
		{
		case TypeTwo::circle:
			info = std::make_unique<circle>(R, H);
			break;
		case TypeTwo::cylinder:
			info = std::make_unique<cylinder>(R, H);
			break;
		default:
			break;
		}
	}
}