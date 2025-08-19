#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "simulation.hpp"

TEST_CASE("controllo stato iniziale") {
  sim::SimulationParameters params(2.0, 3.0, 1.0, 0.5, 0.8, 0.2, 0.001);  // importante il sim:: davanti perchè è riferito al namespace
  // pensandoci bene forse sarebbe meglio dargli due nomi diversti a sti due sim
  //ordine dei numeri x0_, y0_, A_, B_, C_, D_, dt_
  sim::Simulation simulation(params);
  const auto& states = simulation.getStates();
  /* questa riga Quindi restituisce un riferimento
    costante al membro states, che è un
    std::vector<State> contenente tutti gli stati della
    simulazione (ogni stato ha x, y, H).uso const auto&
    perche evita la copia dell'intero std::vector<State>,
    che contine emagari tantissime righe di codice. lo
    rendo const perchè non voglio che questo vettore mi
    si modifichi*/
  CHECK(states.size() == 1); //siccome è lo stato con ripetizioni = 1

  double x_rel_effettiva = 2.0 * 0.8 / 0.2;
  double y_rel_effettiva = 3.0 * 0.5 / 1.0;
  double H_effettivo = simulation.calcolo_H(x_rel_effettiva, y_rel_effettiva);

  CHECK(doctest::Approx(states[0].x) == x_rel_effettiva); //controlla che lo stato iniziale di states sia veramente quello 
  CHECK(doctest::Approx(states[0].y) == y_rel_effettiva);
  CHECK(doctest::Approx(states[0].H) == H_effettivo);

}
  TEST_CASE("controllo avanzamento"){
   sim::SimulationParameters params(2.0, 3.0, 1.0, 0.5, 0.8, 0.2, 0.001);
   sim::Simulation simulation(params);
   simulation.run(10);
   const auto& states = simulation.getStates();
    CHECK(states.size() == 11); // iniziale + 10 ripetizioni 
    CHECK(states[1].x != states[0].x); //controllo che il nuovo stato sia avanzato 
    CHECK(states[1].y != states[0].y);
  }

TEST_CASE("controllo dei valori negativi o nulli dei parametri di input") {
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, -10.0, 4.0, 0.2, 8.0, 0.0003)); //A negativa
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 10.0, -4.0, 0.2, 8.0, 0.0003)); //B negativa
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 10.0, 4.0, -0.2, 8.0, 0.0003)); //C negativa
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 10.0, 4.0, 0.2, -8.0, 0.0003)); //D negativa
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 0.0, 4.0, 0.2, 8.0, 0.0003)); // A = 0
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 3.0, 0.0, 0.2, 8.0, 0.0003)); // B = 0
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 3.0, 4.0, 0.0, 8.0, 0.0003)); // C = 0
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 3.0, 4.0, 0.2, 0.0, 0.0003)); // D = 0
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 4.0, 4.0, 3.0, 8.0, -0.0003)); //dt negativo
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 4.0, 4.0, 3.0, 8.0, 0.0)); // dt = 0
    
}
