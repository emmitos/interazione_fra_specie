#include "simulation.hpp"
#include <cmath>
namespace sim {
Simulation::Simulation(const SimulationParameters& parameters)
    : params(parameters),
state(parameters.x0, parameters.y0, parameters.C, parameters.D, parameters.B,
      parameters.A) {
  double H0 = calcolo_H(state.x_rel, state.y_rel);
  states.push_back({state.x_rel, state.y_rel, H0});
}

double Simulation::calcolo_H(double x, double y) const {
  return -params.D * std::log(x) + params.C * x + params.B * y - params.A * std::log(y);
}

void Simulation::evolve() {
  double x_next = state.x_rel + params.A * (1.0 - state.y_rel) * state.x_rel * params.dt;
  double y_next = state.y_rel + params.D * (state.x_rel - 1.0) * state.y_rel * params.dt;

  state.x_rel = std::abs(x_next);
  state.y_rel = std::abs(y_next);

  double H = calcolo_H(state.x_rel, state.y_rel);
  states.push_back({state.x_rel, state.y_rel, H});
}

void Simulation::run(int ripetizioni) {
  for (int i = 0; i < ripetizioni; ++i) {
    evolve();
  }
}

const std::vector<State>& Simulation::getStates() const {
  return states;
}
} 