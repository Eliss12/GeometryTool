# Geometry Tool
App solving some geometry tasks, written in C++.

As the user starts the program, they must make a choice between two options: to enter names of the lines, points and parabolas, or not.



After that they must make a choice between the following options:  
a. Check if a point lies on a line.  
b. With a given line q and a point p, output an equation of a line, parallel to q and p lies on it.  
c. With a given line q and a point p, lying on it, output an equation of a line perpendicular to q with a heel in p.  
d. With two given lines, find their common point if it exists.  
e. Triangle(set with three points) find the equation of its heights, medians and bisectors.  
f. Triangle(set with three points) find the equation of its heights.  
g. Triangle(set with three points) find the equation of its medians.  
h. Triangle(set with three points) find the equation of its bisectors.  
i. With a given equatation of a parabola and a point, find the equation of the tangent towards the parabola in the given point.  
j. With a given equations of a parabola and a line, find their common points.  
k. With a given equations of four lines, find the type of quadrilateral they form.
  
If the user has chosen to enter names, they are asked to do so.

As the name has to include only Arabic numbers, Latin letters or "_", if the name has any other symbols, the user is asked to enter a new name.  

After choosing one of these options a - k, the user is asked to enter the coordinates of the point(s) and / or the coeficients of the line(s) and / or parabola(s). It must be taken into consideration that the coeficients a, b and c are from the general equation of a line ax + by + c = 0. The coeficients a, b, c as parabola is considered come from the equation: y = ax^2 + bx + c.

After entering the necessary points and lines and / or parabolas, the result is printed. If the user has chosen to enter names, they will see the names in the result messages. If they want to stop using the app, they must press "c" or "C". If the user wants to continue with another task, they must press any other key and they are asked to choose one of the options from a - k. 