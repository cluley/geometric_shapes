#pragma once

#include <string>
#include <vector>
#include <map>
#include <variant>

class Shape
{
public:
	enum class TypeOne {
		line,
		sqr,
		cube
	};

	enum class TypeTwo {
		circle = 3,
		cylinder
	};

	Shape() = default;
	Shape(TypeOne _type, std::multimap<char, std::vector<int>>& _coord);
	Shape(TypeTwo _type, std::multimap<char, std::vector<int>>& _coord, double R, double H);
	std::variant<TypeOne, TypeTwo> getType() { return type; }

	std::variant<TypeOne, TypeTwo> type;
	std::multimap<char, std::vector<int>> coord;
	double volume{ 0 };
	double square{ 0 };
	double height{ 0 };
	double radius{ 0 };
};