#include "simulation.hpp"

#include <cmath>
namespace sim {
Simulation::Simulation(double x0_, double y0_, double A_, double B_, double C_,
                       double D_, double dt_)
    : x0{x0_}, y0{y0_}, A{A_}, B{B_}, C{C_}, D{D_}, dt{dt_} {
  /*double H0 = -D * std::log(x0_) + C * x0_ + B * y0_ -
              A * std::log(y0_);  // calcolo integrale primo */
  double H0 = calcolo_H(x0_, y0_);  // penso sia la stessa cosa della riga sopra
                                    // ma scritto in modo più concreto
  x_rel = x0_ * C / D;
  y_rel = y0_ * B / A;

  states.push_back({x0, y0, H0});  // o ci devo mettere x0_, y0_, H0_??
  // riempie il vettore con i valori di x0,y0 e integrale primo H0
  // for(double x0, y0, H0, std::cin >> x0 >> y0 >> H0) e poi states pushback
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