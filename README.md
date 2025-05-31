##  PROJECT NAME: Ray Bounce Simulator

##  PROJECT DESCRIPTION:
This project is a console-based 3D Ray Bounce Simulator that mathematically models ray-sphere interactions. 
The simulator allows users to define custom parameters such as the sphere's radius and center, the ray's origin 
and direction, and the maximum number of allowed bounces. The primary goal is to compute and visualize the exact 
points where a ray intersects and reflects off the surface of a sphere. An epsilon offset is also used to prevent 
self-intersections at the same point, ensuring more accurate simulation results. The motivation behind this project 
was to deepen my understanding of more advanced C++ concepts such as dynamic memory allocation and key concepts in 
linear algebra, particularly 3D geometry and vector mathematics. Building on these foundations, I aim to apply these 
principles to more advanced topics in computer graphics, physics simulations, and ray tracing engines.

## FEATURES:
- Simulates ray-sphere intersection/reflection
- Supports user-defined ray/sphere parameters and bounce count
- Prevents self-intersections by utilizing epsilon offset
- Implements foundational vector math (dot product, normalization, reflection)
- Clean and modular C++17 code structure

## TOOLS
- C++17
- Microsoft Visual Studio
- C++ Standard Library
- Custom vector math implementation (Vec3)
