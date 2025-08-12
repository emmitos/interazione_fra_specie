#include "simulation.hpp"

#include <cmath>  //mi serve perchè qua devo scrivere le implementazioni di evolve, run e simulation
namespace sim {
Simulation::Simulation(double x0_, double y0_, double A_, double B_, double C_,
                       double D_, double dt_)
    // misa che ci devi aggiungere anche x rel e yrel
    : x0_{x0}, y0_{y0}, A_{A}, B_{B}, C_{C}, D_{D}, dt_{dt} {
        double H0 = -D*std::log(x0) + C*x0 + B*y0 - A*std::log(y0);
        states.push_back({x0, y0, H0});
    }

    void Simulation::evolve() {

    }
    void Simulation::run() {
        
    }
}  // namespace sim