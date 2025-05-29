#include <iostream>


class Vector2
{
public:
	float x{};
	float y{};

	// Constructor
	Vector2(float x = 0, float y = 0) : x(x), y(y) {}

	const Vector2 operator+(const Vector2& other) // Addition
	{
		return (x + other.x, y + other.y);
	}

	const Vector2 operator-(const Vector2& other) // Subtract
	{
		return (x - other.x, y - other.y);
	}

	const float dot(const Vector2& other) // Dot product
	{
		return (x * other.x, y * other.y);
	}
	
	void normalize() // Normalize vector
	{
		float magnitude = std::sqrt((x * x) + (y * y));
		if (magnitude > 0)
		{
			x /= magnitude;
			y /= magnitude;
		}
	}

	const Vector2 reflect(const Vector2& normal) // Reflect
	{
		float dotProduct = this->dot(normal);
		return Vector2(
			x - 2 * dotProduct * normal.x,
			y - 2 * dotProduct * normal.y
		);
	}
};

class Surface
{
	/*
		- Optionally calculate surface normals for reflection logic.
	*/
public:
	Vector2 a{};
	Vector2 b{};
};

class Ray
{
	/*
		- Implement a method to calculate the intersection with a surface.
		- Implement a reflection method to generate a new ray after hitting a surface.
	*/
public:
	Vector2 origin{};
	Vector2 direction{};

	void intersection()
	{

	}

	void rayReflection()
	{

	}
};

/*	- Create a Scene class that holds surfaces.
		- Simulate a ray bounce through multiple surfaces.
		- Store and display ray segments after each bounce.
*/
class Scene
{

};

int main()
{
	/* Prompt user to enter origin of ray, direction of ray, and # of bounces.*/

	/*				Initialization
		- Define several surfaces and add them to a scene.
		- Create an initial ray with user-defined origin and direction.

					Simulation Loop
		- For N bounces:
			- Check for intersection with all surfaces.
			- Find the nearest intersection point.
			- Reflect the ray using surface normal.
			- Log and/or draw the ray segment.

					Display Results
		- Output all segments and bounce points.
		- Optionally show ASCII rendering of the scene.

					Exit Condition
		- After N bounces or when no further intersections are found.
	*/

	return 0;
}