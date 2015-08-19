
#include <vector>
#include "Particle.hpp"
class System
{
	double dt; //the time step. The default time is 10^-3s

private:
	std::vector<Particle> sys;
	double xCOM;
	double yCOM;
	double totalMass;
	int N; //the number of particles in the simulation

	double xRandMin = -10000;
	double xRandMax = -xRandMin;
	double yRandMin = xRandMin; 
	double yRandMax = xRandMax;

	double vRandMax = 100;
	double vRandMin = -100;

	double defaultTime = 0.001;
	double defaultMass = 1;
	const double gravConstant = 1; //Note: This is set to one so that the effects of gravity
								   //are more noticeable in the short-term.
public:
	System();
	/*
		Default constructor
		creates an empty system(N = 0)
	*/

	System(int numberOfParticles);
	/*
		Assigns random positions and velocities to the N particles
		Assigns default_mass to all.
	*/

	/*
	System(int numberOfParticles, char arrangement)
	Arrangement will determine the way the particles are distributed

	's': square arrangement - the particles are arranged in a grid
							- functionality may be included to adjust the vertical/horizontal spacing
	'c': circle arrangement - the particles are arranged along the circumference of a circle
	'l': linear arrangement - the particles are arranged along a line
							- functionality  may be included to adjust the spacing arbitrarily (e.g. logarithmically, etc.)
	*/
	void setTimeStep(double interval){ dt = interval; }
	// Sets the time step to the value stored in interval

	void putAtRest();
	//	Sets all velocities to zero

	void step(); 
	//	Moves all particles in the system by one of specified time steps

	void skipSteps(unsigned int skips);
	// Moves all particles by a "skips" steps in one call. 
	// 

	void stepBy(double time);
	//  Moves all particles in the system by the specified time, in seconds

	double getCOMX();
	//  returns the x-coordinate of the Center Of Mass

	double getCOMY();
	//  returns the y-coordinate of the Center Of Mass

	double getTotalMass(){ return totalMass; };
	// returns the system's total mass

	int getN(){ return N; }
	// returns the number of particles in the system

	double getX(int n);
	// returns the y position of the nth particle

	double getY(int n);
	//return the y coordinate of the nth particle

};