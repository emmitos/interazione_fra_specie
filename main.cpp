#include <iomanip>
#include <iostream>

#include "parameters.hpp"
#include "simulation.hpp"
int main() {

  double x0, y0, A, B, C, D, dt;
  int ripetizioni;
  std::cout
      << "Inserisci lo stato iniziale x0 ed y0, dove x0 è la densità delle "
         "prede "
      << '\n'
      << "allo stato iniziale e y0 la densità dei predatori : " << '\n';
  std::cin >> x0 >> y0;
  if (!std::cin.good()) {
    std::cerr << "Errore: input non valido per x0 o y0, devono essere numeri."
              << '\n';
    return 1;
  }
  std::cout << "Inserisci i parametri A, B, C, D. Dove i parametri A e C "
          << "indicano quanto "
          << '\n'
          << "rapidamente le due specie possono riprodursi, una volta trovato "
          << '\n'
          << "cibo sufficiente; mentre i parametri B e D descrivono il tasso "
          << "di mortalità "
          << '\n'
          << " delle due specie."
          << "Ci sono la specie delle prede e la specie dei predatori."
          << '\n';
  std::cin >> A >> B >> C >> D;
  if (!std::cin.good()) {
    std::cerr << "Errore: input non valido per A, B, C, o D : devono essere numeri."
              << '\n';
    return 1;
  }
  std::cout << "Inserisci il dt, ovvero l'intervallo temporale nel quale si "
               "vuole fare "
            << '\n'
            << "la "
               "simulazione. Sceglierlo dell'ordine di 0.001 : "
            << '\n';
  std::cin >> dt;
  if (dt > 0.01) {
    std::cerr
        << "Warning :  un dt elevato potrebbe causare instabilità numerica."
        << '\n';
  }
  if (!std::cin.good()) {
    std::cerr << "Errore: input non valido per dt deve essere un numero."
              << '\n';
    return 1;
  }
  std::cout << "Inserire le ripetizioni del dt per fare evolvere il sistema. "
               "La durata "
               " totale"
            << '\n'
            << "della simulazione sarà questo valore moltiplicato per "
               "il dt appena inserito. "
            << '\n';
  std::cin >> ripetizioni;
  if (!std::cin.good()) {
    std::cerr << "Errore: input non valido per ripetizioni, devono essere un numero."
              << '\n';
    return 1;
  }
  sim::SimulationParameters params(x0, y0, A, B, C, D, dt);
  sim::Simulation sim(params);
  sim.run(ripetizioni);
  const auto& results = sim.getStates();

  std::cout << "Risultati simulazione:" << '\n';
  std::cout << std::setw(6) << "Passo" << std::setw(12) << "Tempo"
            << std::setw(15) << "Prede (x(t))" << std::setw(18) << "Predatori (y(t))"
            << std::setw(15) << "H(x(t),y(t))" << '\n';

  for (std::size_t i = 0; i < results.size(); ++i) {
    double time = i * dt;
    std::cout << std::setw(6) << i << std::setw(12) << std::fixed
              << std::setprecision(4) << time << std::setw(15) << std::fixed
              << std::setprecision(6) << results[i].x << std::setw(18)
              << std::fixed << std::setprecision(6) << results[i].y
              << std::setw(15) << std::fixed << std::setprecision(6)
              << results[i].H << '\n';
  }

  return 0;


}
