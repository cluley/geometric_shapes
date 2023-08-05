#define _USE_MATH_DEFINES

#include"shape.h"
#include<cmath>

Shape::Shape(int _type, std::map<char, std::vector<int>>& _coord) {
	type = static_cast<Shape::TypeOne>(_type);
	coord = _coord;

	calc_square();
	calc_volume();
}

Shape::Shape(int _type, std::map<char, std::vector<int>>& _coord, double R, double H){
	type = static_cast<Shape::TypeTwo>(_type);
	coord = _coord;
	radius = R;
	height = H;

	calc_square();
	calc_volume();
}

double Shape::calc_square() {
	if (std::holds_alternative<TypeOne>(type))
	{
		int a = abs(coord.find('x')->second[0] - coord.find('x')->second[1]);
		int b = abs(coord.find('y')->second[0] - coord.find('y')->second[1]);
		int c = 0;

		switch (std::get<TypeOne>(type))
		{
		case TypeOne::line:
			square = 0;
			break;
		case TypeOne::sqr:
			square = a * b;
			break;
		case TypeOne::cube:
			c = abs(coord.find('z')->second[0] - coord.find('z')->second[1]);
			square = 2 * a * b + 2 * a * c + 2 * b * c;
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
			square = M_PI * radius * radius;
			break;
		case TypeTwo::cylinder:
			square = M_PI * radius * radius + 2 * radius * height;
			break;
		default:
			break;
		}
	}

	return square;
}

double Shape::calc_volume() {
	if (std::holds_alternative<TypeOne>(type))
	{
		int a = abs(coord.find('x')->second[0] - coord.find('x')->second[1]);
		int b = abs(coord.find('y')->second[0] - coord.find('y')->second[1]);
		int c = 0;

		switch (std::get<TypeOne>(type))
		{
		case TypeOne::line:
			volume = 0;
			break;
		case TypeOne::sqr:
			volume = 0;
			break;
		case TypeOne::cube:
			c = abs(coord.find('z')->second[0] - coord.find('z')->second[1]);
			volume = a * b * c;
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
			volume = 0;
			break;
		case TypeTwo::cylinder:
			volume = M_PI * radius * radius * height;
			break;
		default:
			break;
		}
	}

	return volume;
}