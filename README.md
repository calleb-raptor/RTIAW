## Ray Tracing in a Weekend

##### This is my attempt at RITAW as followed in this resource:

    https://raytracing.github.io/books/RayTracingInOneWeekend.html

##### Lets see how it goes!

### What is ray tracing?

##### Ray tracing is a method of CGI that is now being widely deployed within the game development industry.

##### It allows one to render increasingly lifelike images using solely computer software - this is achieved by:

##### Images in real life are texturised and shaped by light sources that emits a ray of light travelling through air. 4 things may happen with the ray of light as it travels:

##### - absorption

##### - reflection

##### - refraction

##### - fluorescence

##### The way that the light interacts with objects in its way is what allows one to create a 3D feeling of objects and give objects texture and shape.

##### for instance; a ray of light may hit an object and the object may absorb any portion of the light, which results in the intensity of the light diminishing on the other side - this will create a shadow.

##### From Wikipedia: Trace rays from the eye, one per pizel, and find the closest object blocking the path of that ray.

##### An important assumption here is that: if a surface faces a light, the light will reach that surface and not be blocked or in shadow.

##### https://en.wikipedia.org/wiki/Ray_tracing_(graphics)#Detailed_description_of_ray_tracing_computer_algorithm_and_its_genesis

### getting started:

##### Write image to a file (PPM)
