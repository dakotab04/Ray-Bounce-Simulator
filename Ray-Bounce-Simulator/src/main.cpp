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
		return Vector2(x + other.x, y + other.y);
	}

	const Vector2 operator-(const Vector2& other) // Subtract
	{
		return Vector2(x - other.x, y - other.y);
	}

	const float dot(const Vector2& other) // Dot product
	{
		return (x * other.x + y * other.y);
	}
	
	Vector2 normalized() // Normalize vector
	{
		float magnitude = std::sqrt((x * x) + (y * y));
		if (magnitude > 0)
		{
			return Vector2(x / magnitude, y / magnitude);
		}

		return Vector2(0, 0);
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
	// Holds two endpoints, calculates surface normals.
public:
	Vector2 aEndpt{};
	Vector2 bEndpt{};

	std::pair<Vector2, Vector2> calculateNormals()
	{
		Vector2 dir{ bEndpt - aEndpt };
		Vector2 unitDir = dir.normalized();

		// Perpendicular vectors
		Vector2 normal1(unitDir.y, -unitDir.x);
		Vector2 normal2(-unitDir.y, unitDir.x);

		return { normal1, normal2 };
	}
};

class Ray
{
public:
	Vector2 origin{};
	Vector2 direction{};

	void intersection()
		// calculate the intersection with a surface.
	{

	}

	void rayReflection()
		// a reflection method to generate a new ray after hitting a surface.
	{

	}
};

class Scene
{
	/*
		- Simulate a ray bounce through multiple surfaces.
		- Store and display ray segments after each bounce.
	*/
public:
	Vector2 surfaces[]; // Holds surfaces

};

int main()
{
	/* Prompt user to enter origin of ray, direction of ray, and # of bounces.*/
	std::cout << "Enter origin of ray (x y): ";
	int xOrigin{};
	int yOrigin{};
	std::cin >> xOrigin >> yOrigin;

	std::cout << "Enter direction of ray (dx dy): ";
	int xDirection{};
	int yDirection{};
	std::cin >> xDirection >> yDirection;

	std::cout << "Enter number of bounces: ";
	int numBounces{};
	std::cin >> numBounces;



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