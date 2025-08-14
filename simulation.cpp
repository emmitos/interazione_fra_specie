#include "simulation.hpp"

#include <cmath>
namespace sim {
Simulation::Simulation(double x0_, double y0_, double A_, double B_, double C_,
                       double D_, double dt_)
    : x0{x0_}, y0{y0_}, A{A_}, B{B_}, C{C_}, D{D_}, dt{dt_} {
  x_rel = x0_ * C / D;
  y_rel = y0_ * B / A;
  double H0 = calcolo_H(x_rel, y_rel);  // calcolo integrale primo
  states.push_back({x_rel, y_rel, H0});
  /* ma se sto salvando lo stato iniziale non aveva più senso fare
  states.push_back({x0, y0, H0}); ?? solo che poi così non mi funzionavano i
  test riempie il vettore con i valori di x0,y0 e integrale primo H0*/

  if (A <= 0 || B <= 0 || C <= 0 || D <= 0) {
    throw std::runtime_error{
        "I numeri A, B, C, D devono essere reali e maggiori di zero"};
  }
  if (dt <= 0) {
    throw std::runtime_error{
        " L'intervallo temporale deve essere valido e maggiore di zero "};
  }
}

double Simulation::calcolo_H(double x, double y) const {
  return -D * std::log(x) + C * x + B * y - A * std::log(y);
}

void Simulation::evolve() {
  /*double x_rel = x0+ A*(1-y0)*x0*dt;
 double y_rel = y0+ D*(x0-1)*y0*dt;*/
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

}  // namespace sim