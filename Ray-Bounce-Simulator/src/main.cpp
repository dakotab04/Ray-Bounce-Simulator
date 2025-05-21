#include <iostream>

/*	- Create a Vector2 class.
		- Implement operations: add, subtract, dot product, normalize, reflect.
*/
class Vector2
{
public:
	float x{};
	float y{};

	// Constructor
	Vector2(float x = 0, float y = 0) : x(x), y(y) {}


};

/*	- Use a Surface class with two endpoints (Vector2).
		- Optionally calculate surface normals for reflection logic.
*/
class Surface
{

};

/*	- Create a Ray class with an origin and direction.
		- Implement a method to calculate the intersection with a surface.
		- Implement a reflection method to generate a new ray after hitting a surface.
*/
class Ray
{

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