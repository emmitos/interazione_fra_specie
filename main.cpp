#include <iomanip>
#include <iostream>

// #include "parameters.hpp"
#include "simulation.hpp"
int main() {
  /* quando fai i nuovi file.hpp e .cpp ricordati di modificare il
CMakeLists.txt(in realtà solo coin i .cpp tanto gli altri sono inclusi
  ), poi al momento del test aggiungilo di nuovo nel cmake.
  PER COMPILARE : se hai modificato il CMakeLists allora fai : cmake ..
  poi SEMPRE devi fare  : cmake --build . ( per compilare)
  (per eseguire) : ./interazione_fra_specie
*/

  double x0, y0, A, B, C, D,
      dt;  // non so se questi vanno in un namspace...non credo ma bohhhh
  int ripetizioni;
  std::cout
      << "Inserisci lo stato iniziale x0 ed y0, dove x0 è la densità delle "
         "prede allo stato iniziale e y0 la densità dei predatori : "
      << '\n';
  std::cin >> x0 >> y0;
  std::cout << "Inserisci i parametri A, B, C, D. Dove i parametri A e C "
               "indicano quanto "
               " rapidamente le due specie possono riprodursi, una volta "
               "trovato cibo sufficiente; "
               "mentre i parametri B e D descrivono il tasso di mortalità "
               "delle due specie. C'è "
               " la specie delle prede e la specie dei predatori. "
            << '\n';
  if (!(std::cin >> x0 >> y0)) {
    std::cerr << "Errore: input non valido per x0 o y0\n";
    return 1;
}
  std::cin >> A >> B >> C >> D;
  std::cout << "Inserisci il dt, ovvero l'intervallo temporale nel quale si "
               "vuole fare la "
               "simulazione. Sceglierlo dell'ordine di 0.001 : "
            << '\n';
  std::cin >> dt;
  if (dt > 0.01) {
    std::cerr
        << "Warning :  un dt elevato potrebbe causare instabilità numerica."
        << '\n';
  }
  std::cout << "Inserire le ripetizioni del dt per fare evolvere il sistema. "
               "La durata "
               " totale della simulazione sarà questo valore moltiplicato per "
               "il dt appena inserito. "
            << '\n';
  std::cin >> ripetizioni;
  /*
    sim::Simulation sim(x0, y0, A, B, C, D, dt);
    sim.run(ripetizioni);

    // Stampa risultati
    const auto& results = sim.getStates();
    così me li stampava tutti sminchiati :
    std::cout << "Risultati simulazione  : " << '\n';
    std::cout << "Passo \t Prede (x) \t Predatori (y) \t H(x,y) \n";

    for (std::size_t i = 0; i < results.size(); ++i) {
      std::cout << i << results[i].x << '\n';
      std::cout << i << results[i].y << '\n';
      std::cout << i << results[i].H << '\n';
    }

  */

  sim::SimulationParameters params(x0, y0, A, B, C, D, dt);
  sim::Simulation sim(params);
  sim.run(ripetizioni);
  const auto& results = sim.getStates();
  std::cout << "Risultati simulazione:" << '\n';
  std::cout << std::setw(6) << "Passo" << std::setw(12) << "Tempo"
            << std::setw(15) << "Prede (x)" << std::setw(18) << "Predatori (y)"
            << std::setw(15) << "H(x,y)" << '\n';

  /*std::setw imposta la larghezza della colonna, std::precision controlla il
  numero di cifre decimali e poi std::fixed mantiene sempre lo stessso formato
  digitale*/

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
