#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include "parameters.hpp"
#include <vector>

namespace sim {

struct State {
  double x;  // sarebbe il num. di prede (val.assoluto)
  double y;  // num. di predatori
  double H;  // valore integrale primo
};
class Simulation {
  SimulationParameters params;
  RelativeParameters state;
  std::vector<State> states;  // creo un vettore contenitore dinamico che salva
                              // tutti gli stati del sistema e lo chiamo states
  void evolve();  // evolve fa andare avanti la simulazione di un singolo
                  // "passo". Lo voglio void perche non mi deve ritornare un
                  // valore numerico

 public:
  Simulation(const SimulationParameters& parameters);  // costruttore simulation
  void run(int ripetizioni);  // mette evolve in un ciclo e la fa avanzare di
                              // "ripetizioni" volte
  const std::vector<State>& getStates() const;
  // Restituisce tutti gli stati calcolati fino a quel momento
  // (incluso lo stato iniziale), restituisce una reference allo state finale 
  double calcolo_H(double x, double y) const;
};

}  // namespace sim
#endif