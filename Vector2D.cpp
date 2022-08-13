#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::~Vector2D()
{

}

Vector2D Vector2D::operator+(const float& f) const
{
	Vector2D temp(*this);
	temp.x += f;
	temp.y += f;
	return temp;
}

Vector2D Vector2D::operator-(const float& f) const
{
	Vector2D temp(*this);
	temp.x -= f;
	temp.y -= f;
	return temp;
}

Vector2D Vector2D::operator*(const float& f) const
{
	Vector2D temp(*this);
	temp.x *= f;
	temp.y *= f;
	return temp;
}

Vector2D Vector2D::operator/(const float& f) const
{
	Vector2D temp(*this);
	temp.x /= f;
	temp.y /= f;
	return temp;
}

Vector2D Vector2D::operator+(const Vector2D& vector) const
{
	Vector2D temp(*this);
	temp.x += vector.x;
	temp.y += vector.y;
	return temp;
}

Vector2D Vector2D::operator-(const Vector2D& vector) const
{
	Vector2D temp(*this);
	temp.x -= vector.x;
	temp.y -= vector.y;
	return temp;
}

Vector2D Vector2D::operator*(const Vector2D& vector) const
{
	Vector2D temp(*this);
	temp.x *= vector.x;
	temp.y *= vector.y;
	return temp;
}

Vector2D Vector2D::operator/(const Vector2D& vector) const
{
	Vector2D temp(*this);
	temp.x /= vector.x;
	temp.y /= vector.y;
	return temp;
}

Vector2D& Vector2D::operator+=(const float& f)
{
	x += f;
	y += f;
	return *this;
}

Vector2D& Vector2D::operator-=(const float& f)
{
	x -= f;
	y -= f;
	return *this;
}

Vector2D& Vector2D::operator*=(const float& f)
{
	x *= f;
	y *= f;
	return *this;
}

Vector2D& Vector2D::operator/=(const float& f)
{
	x /= f;
	y /= f;
	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vector)
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& vector)
{
	x *= vector.x;
	y *= vector.y;
	return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& vector)
{
	x /= vector.x;
	y /= vector.y;
	return *this;
}

Vector2D& Vector2D::operator=(const Vector2D& vector)
{
	x = vector.x;
	y = vector.y;
	return *this;
}

Vector2D& Vector2D::operator=(const float& f)
{
	x = f;
	y = f;
	return *this;
}

Vector2D Vector2D::Add(const float& f)
{
	return(*this + f);
}

Vector2D Vector2D::Subtract(const float& f)
{
	return(*this - f);
}

Vector2D Vector2D::Multiply(const float& f)
{
	return(*this * f);
}

Vector2D Vector2D::Divide(const float& f)
{
	return(*this / f);
}

Vector2D Vector2D::Sqrt()
{
	Vector2D temp(*this);
	temp.x = sqrtf(temp.x);
	temp.y = sqrtf(temp.y);
	return temp;
}

Vector2D Vector2D::Power(const float& f)
{
	Vector2D temp(*this);
	temp.x = powf(temp.x, f);
	temp.y = powf(temp.y, f);
	return temp;
}

Vector2D Vector2D::Add(const Vector2D& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

Vector2D Vector2D::Subtract(const Vector2D& vector)
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}

Vector2D Vector2D::Multiply(const Vector2D& vector)
{
	x *= vector.x;
	y *= vector.y;
	return *this;
}

Vector2D Vector2D::Divide(const Vector2D& vector)
{
	x /= vector.x;
	y /= vector.y;
	return *this;
}

Vector2D Vector2D::Power(const Vector2D& vector)
{
	Vector2D temp(*this);
	temp.x = powf(temp.x, vector.x);
	temp.y = powf(temp.y, vector.y);
	return temp;
}
