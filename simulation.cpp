#include "simulation.hpp"

#include <cmath>
namespace sim {
/*
  Simulation::Simulation(double x0_, double y0_, double A_, double B_, double
  C_, double D_, double dt_) : x0{x0_}, y0{y0_}, A{A_}, B{B_}, C{C_}, D{D_},
  dt{dt_} { x_rel = x0_ * C / D; y_rel = y0_ * B / A; double H0 =
  calcolo_H(x_rel, y_rel);  // calcolo integrale primo states.push_back({x_rel,
  y_rel, H0};
  ma se sto salvando lo stato iniziale non aveva più senso fare
  states.push_back({x0, y0, H0}); ?? solo che poi così non mi funzionavano i
  test riempie il vettore con i valori di x0,y0 e integrale primo H0

double Simulation::calcolo_H(double x, double y) const {
  return -D * std::log(x) + C * x + B * y - A * std::log(y);
}

void Simulation::evolve() {
  // calcolo delle eq. discretizzate
  double x_rel_next = x_rel + A * (1.0 - y_rel) * x_rel * dt;
  double y_rel_next = y_rel + D * (x_rel - 1.0) * y_rel * dt;

  x_rel = x_rel_next;  // aggiorno le variabili relative
  y_rel = y_rel_next;

  x_rel = std::abs(x_rel);  // per ottenere sempre il valore assoluto
  y_rel = std::abs(y_rel);

  double H = calcolo_H(x_rel, y_rel);  // calcolo integrale primo

  states.push_back({x_rel, y_rel, H});  // salva lo stato nel vettore
}

void Simulation::run(int ripetizioni) {
  for (int i = 0; i < ripetizioni; i++) {
    evolve();
  }
}

const std::vector<State>& Simulation::getStates() const { return states; }
*/

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
}  // namespace sim