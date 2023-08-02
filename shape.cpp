#define _USE_MATH_DEFINES

#include"shape.h"
#include<cmath>

Shape::Shape(TypeOne _type, std::multimap<char, std::vector<int>>& _coord) {
	type = _type;
	coord = _coord;

	int a = abs(coord.find('x')->second[0] - coord.find('x')->second[1]);
	int b = abs(coord.find('y')->second[0] - coord.find('y')->second[1]);
	int c = abs(coord.find('z')->second[0] - coord.find('z')->second[1]);

	switch (std::get<TypeOne>(type))
	{
	case TypeOne::line:
		square = 0;
		break;
	case TypeOne::sqr:
		square = a * b;
		break;
	case TypeOne::cube:
		square = 2 * a * b + 2 * a * c + 2 * b * c;
		break;
	default:
		break;
	}

	switch (std::get<TypeOne>(type))
	{
	case TypeOne::line:
		volume = 0;
		break;
	case TypeOne::sqr:
		volume = 0;
		break;
	case TypeOne::cube:
		volume = a * b * c;
		break;
	default:
		break;
	}
}

Shape::Shape(TypeTwo _type, std::multimap<char, std::vector<int>>& _coord, double R, double H){
	type = _type;
	coord = _coord;
	radius = R;
	height = H;

	// считаем площадь фигуры
	switch (std::get<TypeTwo>(type))
	{
	case TypeTwo::circle:
		square = M_PI * R * R;
		break;
	case TypeTwo::cylinder:
		square = M_PI * R * R + 2 * R * height;
		break;
	default:
		break;
	}

	// считаем объем фигуры
	switch (std::get<TypeTwo>(type))
	{
	case TypeTwo::circle:
		volume = 0;
		break;
	case TypeTwo::cylinder:
		volume = M_PI * R * R * height;
		break;
	default:
		break;
	}
}