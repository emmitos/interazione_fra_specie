#include <iostream>

int main() {
  /* quando fai i nuovi file.hpp e .cpp ricordati di modificare il
CMakeLists.txt(in realtà solo coin i .cpp tanto gli altri sono inclusi
  ), poi al momento del test aggiungilo di nuovo nel cmake.
  PER COMPILARE : se hai modificato il CMakeLists allora fai : build ..
  poi SEMPRE devi fare  : cmake --build . ( per compilare)
  (per eseguire) : ./interazione_fra_specie


  qua pratocamente nel main voglio fare inserire all'utente i miei parametri
principali che saranno x0, y0, A, B , C , D, delta t ( e gli step?) e poi li
esegui : chat dice di fare qualcosa del genere : Simulation sim(x0, y0, A, B, C,
D, dt, steps); sim.run(); auto x = sim.get_x(); auto y = sim.get_y(); auto H =
sim.get_H();

mentre ti dice di fare un file simulation.cpp, simulation.hpp e test.cpp
in simulation.hpp qualcosa el genere : #ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>

class Simulation {
public:
  Simulation(double x0, double y0, double A, double B, double C, double D,
double dt, int steps);

  void evolve();        // evolve di un passo
  void run();           // esegue tutta la simulazione

  const std::vector<double>& get_x() const;
  const std::vector<double>& get_y() const;
  const std::vector<double>& get_H() const;

private:
  double x0_, y0_, A_, B_, C_, D_, dt_;
  int steps_;
  int current_step_;

  std::vector<double> x_vals_;
  std::vector<double> y_vals_;
  std::vector<double> H_vals_;
};

#endif

in simulation.cpp vuoi la dichiarazione di simulation e includi tutto (RICORDATI
NAMESPACE E INCLUDEGUARDS) NEL SIMULATION.CPP :
1. recupera i x_i-1 ^rel e y_i-1 ^ rel
2.Applica la formula di aggiornamento per i valori relativi
3. calcola i nuovi xi = x0 * x_i^rel e y_i = y0 * y_i ^ rel
4. Calcola H_i con la formula che hai
5. salva i valori in x_vals_, y_vals_, H_vals_
*/
}