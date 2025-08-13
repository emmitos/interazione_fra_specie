#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>

namespace sim {
struct State {
  double x;  // sarebbe il num. di prede (val.assoluto)
  double y;  // num. di predatori
  double H;  // valore integrale primo
};
class Simulation {
  // questi sono nella parte privata di default (definizione di classe)
  const double x0, y0, dt;
  const double A, B, C, D;
  double x_rel, y_rel;
  std::vector<State> states;  // creo un vettore contenitore dinamico che salva
                              // tutti gli stati del sistema

 public:
  Simulation(double x0_, double y0_, double A_, double B_, double C_, double D_,
             double dt_);  // costruttore simulation
  void evolve();  // evolve fa andare avanti la simulazione di un singolo
                  // "passo". Lo voglio void perche non mi deve ritornare un
                  // valore numerico
  void run(int ripetizioni);  // mette evolve in un ciclo e la fa avanzare di
                              // "ripetizioni" volte
  const std::vector<State>& getStates() const;
  // Restituisce tutti gli stati calcolati fino a quel momento
  // (incluso lo stato iniziale).
  double calcolo_H(double x, double y) const;
};

}  // namespace sim
#endif