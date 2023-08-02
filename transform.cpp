#include "transform.h"

transform::transform(const Shape& sh)
{
	shape = sh;
}

Shape transform::shift(int m, int n, int k)
{
	switch (std::get<Shape::TypeOne>(shape.getType()))
	{
	case Shape::TypeOne::line:
		for (int i = 0; i < 2; ++i)
		{
			shape.coord.find('x')->second[i] += m;
			shape.coord.find('y')->second[i] += n;
		}
		break;
	case Shape::TypeOne::sqr:
		for (int i = 0; i < 4; ++i)
		{
			shape.coord.find('x')->second[i] += m;
			shape.coord.find('y')->second[i] += n;
		}
		break;
	case Shape::TypeOne::cube:
		for (int i = 0; i < 8; ++i)
		{
			shape.coord.find('x')->second[i] += m;
			shape.coord.find('y')->second[i] += n;
			shape.coord.find('z')->second[i] += k;
		}
		break;
	}
	return shape;
}

Shape transform::scaleX(int a)
{
	switch (std::get<Shape::TypeOne>(shape.getType()))
	{
	case Shape::TypeOne::line:
		for (int i = 0; i < 2; ++i)
		{
			shape.coord.find('x')->second[i] *= a;
		}
		break;
	case Shape::TypeOne::sqr:
		for (int i = 0; i < 4; ++i)
		{
			shape.coord.find('x')->second[i] *= a;
		}
		break;
	case Shape::TypeOne::cube:
		for (int i = 0; i < 8; ++i)
		{
			shape.coord.find('x')->second[i] *= a;
		}
		break;
	}
	return shape;
}

Shape transform::scaleY(int d)
{
	switch (std::get<Shape::TypeOne>(shape.getType()))
	{
	case Shape::TypeOne::line:
		for (int i = 0; i < 2; ++i)
		{
			shape.coord.find('y')->second[i] *= d;
		}
		break;
	case Shape::TypeOne::sqr:
		for (int i = 0; i < 4; ++i)
		{
			shape.coord.find('y')->second[i] *= d;
		}
		break;
	case Shape::TypeOne::cube:
		for (int i = 0; i < 8; ++i)
		{
			shape.coord.find('y')->second[i] *= d;
		}
		break;
	}
	return shape;
}

Shape transform::scaleZ(int e)
{
	switch (std::get<Shape::TypeOne>(shape.getType()))
	{
	case Shape::TypeOne::line:
		for (int i = 0; i < 2; ++i)
		{
			shape.coord.find('z')->second[i] *= e;
		}
		break;
	case Shape::TypeOne::sqr:
		for (int i = 0; i < 4; ++i)
		{
			shape.coord.find('z')->second[i] *= e;
		}
		break;
	case Shape::TypeOne::cube:
		for (int i = 0; i < 8; ++i)
		{
			shape.coord.find('z')->second[i] *= e;
		}
		break;
	}
	return shape;
}

Shape transform::scale(int s)
{
	switch (std::get<Shape::TypeOne>(shape.getType()))
	{
	case Shape::TypeOne::line:
		for (int i = 0; i < 2; ++i)
		{
			shape.coord.find('x')->second[i] /= s;
			shape.coord.find('y')->second[i] /= s;
		}
		break;
	case Shape::TypeOne::sqr:
		for (int i = 0; i < 4; ++i)
		{
			shape.coord.find('x')->second[i] /= s;
			shape.coord.find('y')->second[i] /= s;
		}
		break;
	case Shape::TypeOne::cube:
		for (int i = 0; i < 8; ++i)
		{
			shape.coord.find('x')->second[i] /= s;
			shape.coord.find('y')->second[i] /= s;
			shape.coord.find('z')->second[i] /= s;
		}
		break;
	}

	return shape;
}