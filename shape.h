#pragma once

#include <string>
#include <vector>
#include <map>
#include <variant>
#include <memory>

class Figure {
public:
	virtual void calc_volume();
	virtual void calc_square();
	virtual ~Figure() {}
};

class line : public Figure {
public:
	void calc_volume() override;
	void calc_square() override;
};

class sqr : public Figure {
public:
	void calc_volume() override;
	void calc_square() override;
};

class cube : public Figure {
public:
	void calc_volume() override;
	void calc_square() override;
};

class circle : public Figure {
public:
	void calc_volume() override;
	void calc_square() override;
};

class cylinder : public Figure {
public:
	void calc_volume() override;
	void calc_square() override;
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
	Shape(int _type, std::map<char, std::vector<int>>& _coord);
	Shape(int _type, std::map<char, std::vector<int>>& _coord, double R, double H);

	std::variant<TypeOne, TypeTwo> getType() { return type; }
	std::map<char, std::vector<int>> getCoord() { return coord; }

	double calc_square();
	double calc_volume();
private:
	std::variant<TypeOne, TypeTwo> type;
	std::map<char, std::vector<int>> coord;
	std::shared_ptr<Figure> info;
	double volume{ 0 };
	double square{ 0 };
	double height{ 0 };
	double radius{ 0 };
};