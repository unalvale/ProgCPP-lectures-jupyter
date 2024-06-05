#include <iostream>
#include <vector>
#include <string>
#include <map>

// modelar la particula
class Particle {
public:
  double Rz = 0.0, Vz = 0.0, Fz = 0.0;
  double mass = 1.0;

  Particle(){};
  ~Particle(){};
};
void initial_conditions(std::vector<Particle> & particles);
void compute_forces(std::vector<Particle> & particles, std::map<std::string, double> &params);
void start_time_integration(std::vector<Particle> & particles, std::map<std::string, double> &params);
void time_step(std::vector<Particle> & particles, std::map<std::string, double> &params);
void print(const std::vector<Particle> & particles, std::map<std::string, double> &params, double time);

int main(int argc, char *argv[]) {
  const int N = 1;
  std::vector<Particle> particles(N);

  // parametros
  std::map<std::string, double> PARAMS;
  PARAMS["G"] = 9.81;
  PARAMS["B"] = 1.81;
  PARAMS["DT"] = 0.01;
  PARAMS["T0"] = 0.0;
  PARAMS["TF"] = 2.3456;
  PARAMS["NSTEPS"] = int((PARAMS["TF"]-PARAMS["T0"])/PARAMS["DT"]);


  // condiciones iniciales
  initial_conditions(particles);
  compute_forces(particles, PARAMS);
  start_time_integration(particles, PARAMS);

  // temporal loop
  for (int istep = 0; istep <= PARAMS["NSTEPS"]; ++istep) {
	  compute_forces(particles, PARAMS);
	  time_step(particles, PARAMS);
	  print(particles, PARAMS, PARAMS["T0"] + istep*PARAMS["DT"]);
  }


  return 0;
}

void initial_conditions(std::vector<Particle> & particles) {
  // condiciones iniciales
  particles[0].mass = 1.987;
  particles[0].Rz = 1.21323432;
  particles[0].Vz = +3.21323432;
}


void compute_forces(std::vector<Particle> &particles, std::map<std::string, double> &params) {
	// reset forces
	for (auto & body : particles) {
		body.Fz = 0.0;
	}
	// Add gravitational forces
	for (auto & body : particles) {
		body.Fz -= body.mass*params["G"];
	}
	// Add damping vertical force
	for (auto & body : particles) {
		body.Fz -= body.mass*params["B"]*body.Vz;
	}
}

void start_time_integration(std::vector<Particle> &particles,
                            std::map<std::string, double> &params) {
	for (auto & body : particles) {
		body.Vz = body.Vz - 0.5*params["DT"]*body.Fz/body.mass;
	}
}


void time_step(std::vector<Particle> &particles,
               std::map<std::string, double> &params) {
	// leap-frog
	for (auto & body : particles) {
		body.Vz = body.Vz + params["DT"]*body.Fz/body.mass;
		body.Rz = body.Rz + params["DT"]*body.Vz;
	}
}


void print(const std::vector<Particle> &particles,
           std::map<std::string, double> &params, double time) {
	std::cout << time << " ";
	for (const auto & body : particles) {
		std::cout << body.mass << " " << body.Rz << " " << body.Vz << " " << body.Fz << " ";
    }
	std::cout << "\n";
}
