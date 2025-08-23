#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include "parameters.hpp"
#include <vector>

namespace sim {

struct State {
  double x;  
  double y;  
  double H; 
};
class Simulation {
  SimulationParameters params;
  RelativeParameters state;
  std::vector<State> states;
  void evolve();
 public:
  Simulation(const SimulationParameters& parameters);  
  void run(int ripetizioni);  
  const std::vector<State>& getStates() const;
  double calcolo_H(double x, double y) const;
};

}
#endif