#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

// we use the arrow operator to access objects from a pointer
class Coord3D {
public:
    double x;
    double y;    
    double z;
};     
// compute the distance
double length(Coord3D *p)  // pass the coordinates as pointers
{
   double euclidean_vector_length = sqrt(p->x * p->x + p->y* p->y + p->z * p->z);   // our length function uses the euclidean distance formula to compute 
   return euclidean_vector_length;  // the distance of our coordinates from the origin


}

Coord3D* fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    double p1length = length(p1);
    double p2length = length(p2);

    if (p1length > p2length) {
        return p1;
    } else {
        return p2;
    }
}
void move(Coord3D* ppos, Coord3D* pvel, double dt) {
    ppos->x += pvel->x * dt; // Update x coordinate based on velocity
    ppos->y += pvel->y * dt; // Update y coordinate based on velocity
    ppos->z += pvel->z * dt; // Update z coordinate based on velocity
}
// allocate memory and initialize
Coord3D* createCoord3D(double x,double y ,double z){
    Coord3D*p = new Coord3D;
    (*p).x = x;
    (*p).y = y;
    (*p).z = z;
    return p;
}

// free memory
void deleteCoord3D(Coord3D *p){
    delete p;  // we use the delete
}


// andy lafleur

// tong yi

// lab 9

//1
//2