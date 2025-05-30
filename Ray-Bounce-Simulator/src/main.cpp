#include <iostream>

class Vector3
{
	// Represent a 3D vector or point, and provide all basic vector math operations.
public:
	float x;
	float y;
	float z;

	// Constructor
	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3 operator+(const Vector3& other) const // Addition
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}
	
	Vector3 operator-(const Vector3& other) const // Subtraction
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3 operator*(float scalar) const // Scalar
	{
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	float dot(const Vector3& other) const // Dot product
	{
		return (x * other.x + y * other.y + z * other.z);
	}

	Vector3 cross(const Vector3& other) const // cross product
	{
		return Vector3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	float length() const // Magnitude
	{
		return std::sqrt((x * x) + (y * y) + (z * z));
	}

	Vector3 normalized() const // Normalize
	{
		float magnitude = length();

		if (magnitude > 0.0f)
		{
			return Vector3(x / magnitude, y / magnitude, z / magnitude);
		}
		else
		{
			std::cerr << "Invalid. Cannot normalize 0.0 vector.\n";
		}
	}
};

class Ray
{
	// Represent a ray in 3D defined by an origin and a direction.
public:
	Vector3 origin;
	Vector3 direction; // must be normalized

	// Constructor
	Ray(const Vector3& origin, const Vector3& direction)
		: origin(origin), direction(direction.length() > 0.0f ? direction.normalized() : Vector3(0.0f, 0.0f, 0.0f))
	{
		if (direction.length() == 0.0f)
		{
			std::cerr << "Warning: Ray direction is a zero vector. Normalization skipped.\n";
		}
	}

	Vector3 pointAtParameter(float t) const
		// Returns point = origin + direction * t.
	{
		Vector3 point = origin + direction * t;
		return point;
	}
};

class Sphere
{
	// Represent a sphere with a center and radius. Provide ray-sphere intersection.
public:
	Vector3 center;
	float radius;

	// Constructor
	Sphere(const Vector3& center, float radius)
		: center(center), radius(radius)
	{
		if (radius < 0.0f)
		{
			std::cerr << "Warning: Sphere radius is negative. Setting to 0.\n";
			this->radius = 0.0f;
		}
	};

	bool intersect(const Ray& ray, float& t) const
		// Returns true if ray intersects with sphere, false otherwise.
	{

	}
};

int main()
{
	// Start: this can be changed to prompt the user later.
	Sphere sphere(Vector3(0.0f, 0.0f, 0.0f), 10.0f); // Create sphere with radius of 10 and center of 0, 0, 0
	Ray ray(Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f)); // Create ray with origin of 0, 0, 0 and direction of 1, 1, 1
	int bounce_limit = 3; // Set bounce limit

	for (int i = 0; i < bounce_limit; ++i) // For every bounce:
	{
		float t = 5.0f; // t is a scalar that stretches or shrinks the direction vector
		if (sphere.intersect(ray, t)) // If ray hits the sphere:
		{
			// Handle bounce logic here
		}
		else // If ray doesn't hit the sphere:
		{
			std::cout << "Not hit, done.\n";
			break;
		}
	}


	/*
	Loop
	1. Repeat up to 3 times:
		Does the ray hit the sphere?
		2. If no -> stop and say "no hit, done."
		3. If yes:
			- Find the exact spot it hits
			- Get the surface normal at that spot.
			- Show the hit point (print it).
			- Bounce the ray: calculate its new direction.
			- Move the ray's starting point to the hit point.
			- Use the new direction to keep going.

	End
	1. When done bouncing or no hit -> stop.
	*/

	return 0; // Program has successfully run
}