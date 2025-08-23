#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "simulation.hpp"

TEST_CASE("controllo stato iniziale") {
  sim::SimulationParameters params(2.0, 3.0, 1.0, 0.5, 0.8, 0.2, 0.001); 
  sim::Simulation simulation(params);
  const auto& states = simulation.getStates();
  
  CHECK(states.size() == 1); 

  double x_rel_effettiva = 2.0 * 0.8 / 0.2;
  double y_rel_effettiva = 3.0 * 0.5 / 1.0;
  double H_effettivo = simulation.calcolo_H(x_rel_effettiva, y_rel_effettiva);

  CHECK(doctest::Approx(states[0].x) == x_rel_effettiva); 
  CHECK(doctest::Approx(states[0].y) == y_rel_effettiva);
  CHECK(doctest::Approx(states[0].H) == H_effettivo);

}
  TEST_CASE("controllo avanzamento"){
   sim::SimulationParameters params(2.0, 3.0, 1.0, 0.5, 0.8, 0.2, 0.001);
   sim::Simulation simulation(params);
   simulation.run(10);
   const auto& states = simulation.getStates();
    CHECK(states.size() == 11); 
    CHECK(states[1].x != states[0].x); 
    CHECK(states[1].y != states[0].y);
  }

TEST_CASE("controllo dei valori negativi o nulli dei parametri di input") {
    CHECK_THROWS(sim::SimulationParameters(-2.0, 2.5, 10.0, 4.0, 0.2, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, -2.5, 10.0, 4.0, 0.2, 8.0, 0.0003));
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, -10.0, 4.0, 0.2, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 10.0, -4.0, 0.2, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 10.0, 4.0, -0.2, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 10.0, 4.0, 0.2, -8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 4.0, 4.0, 3.0, 8.0, -0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(0.0, 2.5, 10.0, 4.0, 0.2, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 0.0, 10.0, 4.0, 0.2, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 0.0, 4.0, 0.2, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 3.0, 0.0, 0.2, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 3.0, 4.0, 0.0, 8.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 3.0, 4.0, 0.2, 0.0, 0.0003)); 
    CHECK_THROWS(sim::SimulationParameters(1.0, 2.5, 4.0, 4.0, 3.0, 8.0, 0.0)); 
    
}
