#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

// modelar la particula
class Particle {
public: // visibilidad de todo lo que esta debajo mio
  //double Rz = 0.0, Vz = 0.0, Fz = 0.0;
  std::vector<double> R{0.0, 0.0, 0.0}, V{0.0, 0.0, 0.0}, F{0.0, 0.0, 0.0};
  double mass = 1.0;

  Particle(){}; // constructor
  ~Particle(){}; // destructor
};

void initial_conditions(std::vector<Particle> & particles);
void compute_forces(std::vector<Particle> & particles, std::map<std::string, double> &params);
void start_time_integration(std::vector<Particle> & particles, std::map<std::string, double> &params);
void time_step(std::vector<Particle> & particles, std::map<std::string, double> &params);
void print(const std::vector<Particle> & particles, std::map<std::string, double> &params, int iter, double time);

int main(int argc, char *argv[]) {
  const int N = 1;
  std::vector<Particle> particles{N};

  // parametros
  std::map<std::string, double> PARAMS;
  PARAMS["G"] = 9.81; // Gravity module, m/s^2
  PARAMS["B"] = 0.0; // Damping strength, 1/s
  PARAMS["DT"] = 0.01; // Time step size, s
  PARAMS["T0"] = 0.0; // Initial time, s
  PARAMS["TF"] = 2.3456; // Final time, s 
  PARAMS["NSTEPS"] = int((PARAMS["TF"]-PARAMS["T0"])/PARAMS["DT"]); // [-]


  // condiciones iniciales
  initial_conditions(particles);
  compute_forces(particles, PARAMS);
  start_time_integration(particles, PARAMS);

  // temporal loop
  for (int istep = 0; istep <= PARAMS["NSTEPS"]; ++istep) {
    compute_forces(particles, PARAMS);
    time_step(particles, PARAMS);
    print(particles, PARAMS, istep, PARAMS["T0"] + istep*PARAMS["DT"]);
  }


  return 0;
}

void initial_conditions(std::vector<Particle> & particles) {
  // condiciones iniciales
  particles[0].mass = 1.987;
  particles[0].R[2] = 1.21323432;
  particles[0].V[2] = +3.21323432;
}


void compute_forces(std::vector<Particle> &particles, std::map<std::string, double> &params) {
  // reset forces
  for (auto & body : particles) {
    //body.Fz = 0.0;
    for (int ii = 0; ii < 3; ii++) {
      body.F[ii] = 0.0;
    }
  }
  // Add gravitational forces
  for (auto & body : particles) {
    body.F[2] -= body.mass*params["G"];
  }
  // Add damping vertical force
  for (auto & body : particles) {
    body.F[2] -= body.mass*params["B"]*body.V[2];
  }
}

void start_time_integration(std::vector<Particle> &particles,
                            std::map<std::string, double> &params) {
  for (auto & body : particles) {
    //body.Vz = body.Vz - 0.5*params["DT"]*body.Fz/body.mass;
    for (int ii = 0; ii < 3; ii++) {
      body.V[ii] = body.V[ii] - 0.5*params["DT"]*body.F[ii]/body.mass;
    }
  }
}


void time_step(std::vector<Particle> &particles,
               std::map<std::string, double> &params) {
  // leap-frog
  for (auto & body : particles) {
    for (int ii = 0; ii < 3; ii++) {
      body.V[ii] = body.V[ii] + params["DT"]*body.F[ii]/body.mass;
      body.R[ii] = body.R[ii] + params["DT"]*body.V[ii];
    }
  }
}


void print(const std::vector<Particle> &particles,
           std::map<std::string, double> &params, int iter, double time) {
  // creates a file per time step
  
  // set the filename: datos-{istep}.txt
  std::string fname = "DISPLAY/datos-" + std::to_string(iter) + ".txt";  
  
  // open the file
  std::ofstream fout(fname);
  
  // write data
  fout << time << " ";
  for (const auto & body : particles) {
    fout << body.mass << " " ;
    for (int ii = 0; ii < 3; ii++) {
      fout << body.R[ii] << " " << body.V[ii] << " " << body.F[ii] << " ";
    }
  }
  fout << "\n";
  // close the file
  fout.close();
}
