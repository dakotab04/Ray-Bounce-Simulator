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
			return Vector3(0.0f, 0.0f, 0.0f);
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
		Vector3 oc = ray.origin - center;
		float a = ray.direction.dot(ray.direction);
		float b = 2.0f * oc.dot(ray.direction);
		float c = oc.dot(oc) - radius * radius;

		float discriminant = b * b - 4 * a * c;

		if (discriminant < 0) // If there is no hit
		{
			return false;
		}
		else
		{
			// Return the nearest t value (smallest positive root)
			t = (-b - std::sqrt(discriminant)) / (2.0f * a); // Closest point
			if (t < 0)
			{
				t = (-b + std::sqrt(discriminant)) / (2.0f * a); // Second point
				if (t < 0)
					return false;
			}
			return true; // Hit
		}
	}
};

int main()
{
	// Start
	std::cout << "Enter the radius of your sphere: ";
	float radius{};
	std::cin >> radius;

	std::cout << "Enter the center point of your sphere (x y z): ";
	float x_center{}, y_center{}, z_center{};
	std::cin >> x_center >> y_center >> z_center;
	Sphere sphere(Vector3(x_center, y_center, z_center), radius);

	std::cout << "Enter the origin of your ray (x y z): ";
	float x_origin{}, y_origin{}, z_origin{};
	std::cin >> x_origin >> y_origin >> z_origin;

	std::cout << "Enter the direction of your ray (x y z): ";
	float x_direction{}, y_direction{}, z_direction{};
	std::cin >> x_direction >> y_direction >> z_direction;
	Ray ray(Vector3(x_origin, y_origin, z_origin), Vector3(x_direction, y_direction, z_direction));

	std::cout << "Enter the limit of bounces: ";
	int bounce_limit{};
	std::cin >> bounce_limit;

	for (int i = 0; i < bounce_limit; ++i)
	{
		float t = 5.0f;
		if (sphere.intersect(ray, t))
		{
			Vector3 hitPoint = ray.pointAtParameter(t);
			Vector3 normal = (hitPoint - sphere.center).normalized();

			// Move the hit point slightly along the normal to prevent self-intersection
			const float epsilon = 0.0001f;
			hitPoint = hitPoint + normal * epsilon;

			Vector3 reflectedDirection = ray.direction - normal * 2.0f * ray.direction.dot(normal);
			ray = Ray(hitPoint, reflectedDirection);

			std::cout << "Bounce " << i + 1 << ": Hit at ("
				<< hitPoint.x << ", "
				<< hitPoint.y << ", "
				<< hitPoint.z << "), "
				<< "Reflected direction: ("
				<< reflectedDirection.x << ", "
				<< reflectedDirection.y << ", "
				<< reflectedDirection.z << ")\n";
		}
		else
		{
			std::cout << "Not hit, done.\n";
			break;
		}
	}

	return 0;
}
