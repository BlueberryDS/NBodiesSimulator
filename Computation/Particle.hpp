#ifndef PARTICLE
#define PARTICLE

#include <math.h>
class Particle
{/*
 This is the particle class. The app operates on a two-dimensional plane
 */
public:
	double mass;
	struct {
		double x;
		double y;
	}pos;
	
	struct {
		double x;
		double y;
	}vel;

	Particle(double m) : mass(m){}

	double dist_sqr(Particle p)
	{ /*
			Computes the square of the distance between p and this particle.
	  */
	
		return (pos.x - p.pos.x)*(pos.x - p.pos.x) + (pos.y - p.pos.y)*(pos.y - p.pos.y);
	}

	double distance(Particle p)
	{/*
			Computes the distance between p and this particle.
	 */
		return sqrt(Particle::dist_sqr(p));
	}
}; 
#endif

