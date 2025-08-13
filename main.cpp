#include <iostream>

#include "simulation.hpp"
int main() {
  /* quando fai i nuovi file.hpp e .cpp ricordati di modificare il
CMakeLists.txt(in realtà solo coin i .cpp tanto gli altri sono inclusi
  ), poi al momento del test aggiungilo di nuovo nel cmake.
  PER COMPILARE : se hai modificato il CMakeLists allora fai : cmake ..
  poi SEMPRE devi fare  : cmake --build . ( per compilare)
  (per eseguire) : ./interazione_fra_specie


  qua pratocamente nel main voglio fare inserire all'utente i miei parametri
principali che saranno x0, y0, A, B , C , D, delta t ( e gli step?) e poi li
esegui : chat dice di fare qualcosa del genere : Simulation sim(x0, y0, A, B, C,
D, dt, steps); sim.run(); auto x = sim.get_x(); auto y = sim.get_y(); auto H =
sim.get_H();
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
  std::cin >> A >> B >> C >> D;
  if (A <= 0 || B <= 0 || C <= 0 || D <= 0) {
    throw std::runtime_error{
        "I numeri A, B, C, D devono essere reali e maggiori di zero"};
  }
  std::cout << "Inserisci il dt, ovvero l'intervallo temporale nel quale si "
               "vuole fare la "
               "simulazione. Sceglierlo dell'ordine di 0.001 : "
            << '\n';
  std::cin >> dt;
  if (dt <= 0) {
    throw std::runtime_error{
        " L'intervallo temporale deve essere valido e maggiore di zero "};
  }
  std::cout << "Inserire le ripetizioni del dt per fare evolvere il sistema. "
               "La durata "
               " totale della simulazione sarà questo valore moltiplicato per "
               "il dt appena inserito. "
            << '\n';
  std::cin >> ripetizioni;

  sim::Simulation sim(x0, y0, A, B, C, D, dt);
  sim.run(ripetizioni);

  // Stampa risultati
  const auto& results = sim.getStates();
  std::cout << "Risultati simulazione";
  std::cout << "Passo\tPrede (x)\tPredatori (y)\tH(x,y)\n";

  for (std::size_t i = 0; i < results.size(); ++i) {
    std::cout << i << '\t' << results[i].x << '\t' << results[i].y << '\t'
              << results[i].H << '\n';
  }

  return 0;
}
