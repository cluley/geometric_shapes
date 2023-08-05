#pragma once

#define _USE_MATH_DEFINES

#include <string>
#include <vector>
#include <map>
#include <variant>
#include <memory>

using coordinates = std::map<char, std::vector<int>>;

class Figure {
public:
	virtual double square(coordinates& coord) = 0;
	virtual double volume(coordinates& coord) = 0;
	double height{ 0 };
	double radius{ 0 };
};

class line : public Figure {
public:
	double square(coordinates& coord) override;
	double volume(coordinates& coord) override;
};

class sqr : public Figure {
public:
	double square(coordinates& coord) override;
	double volume(coordinates& coord) override;
};

class cube : public Figure {
public:
	double square(coordinates& coord) override;
	double volume(coordinates& coord) override;
};

class circle : public Figure {
public:
	circle(const double& R, const double& H) : radius(R), height(H) {}
	double square(coordinates& coord) override;
	double volume(coordinates& coord) override;
	double radius{ 0 };
	double height{ 0 };
};

class cylinder : public Figure {
public:
	cylinder(const double& R, const double& H) : radius(R), height(H) {}
	double square(coordinates& coord) override;
	double volume(coordinates& coord) override;
	double radius{ 0 };
	double height{ 0 };
};

class Shape
{
public:
	enum class TypeOne {
		line = 1,
		sqr,
		cube
	};

	enum class TypeTwo {
		circle = 4,
		cylinder
	};

	Shape() = default;
	Shape(int _type, coordinates& _coord);
	Shape(int _type, coordinates& _coord, const double R, const double H);

	std::variant<TypeOne, TypeTwo> getType() { return type; }
	coordinates getCoord() { return coord; }
	double getSquare() { return info->square(coord); }
	double getVolume() { return info->volume(coord); }
	double getHeight() { return info->height; }
	double getRadius() { return info->radius; }
private:
	void calc_info(const double R = 0, const double H = 0);

	std::variant<TypeOne, TypeTwo> type;
	coordinates coord;
	std::shared_ptr<Figure> info;
};