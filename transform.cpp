#include "transform.h"

transform::transform(const Shape& sh)
{
	shape = sh;
}

Shape transform::shift(int m, int n, int k)
{
	for (auto& x : shape.getCoord().find('x')->second)
		x += m;

	for (auto& y : shape.getCoord().find('y')->second)
		y += n;

	if (shape.getCoord().contains('z'))
	{
		for (auto& z : shape.getCoord().find('z')->second)
			z += k;
	}

	return shape;
}

Shape transform::scaleX(int a)
{
	for (auto& x : shape.getCoord().find('x')->second)
		x *= a;

	return shape;
}

Shape transform::scaleY(int d)
{
	for (auto& y : shape.getCoord().find('y')->second)
		y *= d;

	return shape;
}

Shape transform::scaleZ(int e)
{
	if (shape.getCoord().contains('z'))
	{
		for (auto& z : shape.getCoord().find('z')->second)
			z *= e;
	}

	return shape;
}

Shape transform::scale(int s)
{
	for (auto& x : shape.getCoord().find('x')->second)
		x /= s;

	for (auto& y : shape.getCoord().find('y')->second)
		y /= s;

	if (shape.getCoord().contains('z'))
	{
		for (auto& z : shape.getCoord().find('z')->second)
			z /= s;
	}

	return shape;
}