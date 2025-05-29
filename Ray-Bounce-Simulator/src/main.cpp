#include <iostream>

class Vector3
{
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

int main()
{
	return 0; // Program has successfully run
}