#ifndef SYSTEM
#define SYSTEM


#include <stdlib.h>
#include "System.hpp"
#include <vector>
#include "Particle.hpp"

System::System(){
	N = 0;
	std::vector < Particle > sys;
	dt = defaultTime;
	totalMass = 0;
}
System::System(int numberOfParticles) {
	N = numberOfParticles;
	dt = defaultTime;
	std::vector < Particle > sys;

	for (int i = 0; i < N; i++)
	{
		Particle p(defaultMass);
		p.pos.x = rand()*(xRandMax - xRandMin) + xRandMin;
		p.pos.y = rand()*(yRandMax - yRandMin) + yRandMin;
		p.vel.x = rand()*(vRandMax - vRandMin) + vRandMin;
		p.vel.y = rand()*(vRandMax - vRandMin) + vRandMin;
		totalMass += defaultMass;
		sys.push_back(p);
	}
}

void System::putAtRest()
{
	for (int i = 0; i < N; i++)
		sys[i].vel.x = (sys[i].vel.y = 0);
}

void System::step()
{
	std::vector<double> xNew;
	std::vector<double> yNew;
	std::vector<double> vxNew;
	std::vector<double> vyNew;

	for (int i = 0; i < N; i++)
	{
		xNew.push_back(sys[i].pos.x);
		yNew.push_back(sys[i].pos.y);
		vxNew.push_back(sys[i].vel.x);
		vyNew.push_back(sys[i].vel.y);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			double dist_x = abs(sys[i].pos.x - sys[j].pos.x);
			double dist_y = abs(sys[i].pos.y - sys[j].pos.y);
			double dist = sqrt(dist_x*dist_x + dist_y*dist_y);

			//double force = gravConstant*sys[i].mass*sys[j].mass / (dist*dist);

			double accel_i = gravConstant*sys[j].mass / (dist*dist);
			double accel_j = gravConstant*sys[i].mass / (dist*dist);

			double accel_i_x = accel_i * dist_x / dist;
			double accel_i_y = accel_i * dist_y / dist;

			double accel_j_x = accel_j * dist_x / dist;
			double accel_j_y = accel_j * dist_y / dist;

			xNew[i] += (0.5*accel_i_x*dt*dt);
			vxNew[i] += (accel_i_x*dt);
			yNew[i] += (0.5*accel_i_y*dt*dt);
			vyNew[i] += (accel_i_y*dt);

			xNew[j] += (0.5*accel_j_x*dt*dt);
			vxNew[j] += (accel_j_x*dt);
			yNew[j] += (0.5*accel_j_y*dt*dt);
			vyNew[j] += (accel_j_y*dt);
		}
	}

	for (int i = 0; i < N; i++)
	{
		sys[i].pos.x = xNew[i];
		sys[i].pos.y = yNew[i];
		sys[i].vel.x = vxNew[i];
		sys[i].vel.y = vyNew[i];
	}
}

double System::getCOMX()
{
	double mxTOT;
	for (int i = 0; i < N; i++)
		mxTOT += (sys[i].mass*sys[i].pos.x);

	return mxTOT / totalMass;
}

double System::getCOMY()
{
	double myTOT;
	for (int i = 0; i < N; i++)
		myTOT += (sys[i].mass*sys[i].pos.y);

	return myTOT / totalMass;
}

void System::skipSteps(int skips)
{
	for (int i = 0; i < skips; i++)
		step();
}

void System::stepBy(double time)
{
	int numOfSteps = floor(time / dt);
	return skipSteps(numOfSteps);
}
//  Moves all particles in the system by the specified time, in seconds
#endif