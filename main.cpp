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

in simulation.cpp vuoi la dichiarazione di simulation e includi tutto
(NAMESPACE SIA IN .CPP CHE IN .HPP MA INCLUDEGUARDS NELL'.HPP) NEL
SIMULATION.CPP :
1. recupera i x_i-1 ^rel e y_i-1 ^ rel
2.Applica la formula di aggiornamento per i valori relativi
3. calcola i nuovi xi = x0 * x_i^rel e y_i = y0 * y_i ^ rel
4. Calcola H_i con la formula che f
5. salva i valori in x_vals_, y_vals_, H_vals_



viene richiesto di sviluppare una simulazione che, introdotto uno stato iniziale
(x_0,y_0) ed una serie di parametri A,B,C,D validi, utilizzi la versione  delle
equazioni di Lotka-Volterra presentata in 1* (se ti serve te la scrivo) per
calcolare, ad ogni passo dell'evoluzione, i valori (x_i, y_i, H_i). Dove H è
l'integrale primo , infatti sistema è caratterizzato da un integrale primo che
rimane costante nel tempo: H(x,y) = -Dln(x)+Cx+By-Aln(y) La durata totale della
simulazione, espressa in multipli interi dell'unità di tempo Δt, deve essere una
variabile che l'utente può introdurre a runtime.

Oltre alle caratteristiche minime che ogni progetto deve soddisfare (ovvero
almeno due translation unit, alcune richieste sul linguaggio e anche la
scrittura di una serie di unit test con doctest), in questo caso sono posti
alcuni vincoli ulteriori.

In primis, la descrizione del sistema deve essere implementata tramite una
classe Simulation la quale deve, quantomeno:

- contenere un metodo evolve() che permetta di fare progredire la simulazione di
una singola unità Δt -  ---  - mantenere al suo interno i valori assoluti (x_i,
y_i, H_i)  per tutti gli stati di evoluzione del sistema e renderli accessibili
all'utente per eventuali stampe su schermo o analisi. In secondo luogo, al fine
di migliorare la stabilità del calcolo numerico, si richiede di:

- utilizzare valori di  Δt dell'ordine di 0.001;
- rappresentare internamente lo stato del sistema ad un dato istante t in
termini di (x_i ^rel, y_i^rel)
- implementare il metodo evolve() utilizzando la formula descritta in [1] che fa
uso dei valori relativi (x_i ^rel, y_i^rel) [1] : x_i ^rel = x_(i-1) ^rel +
A(1-y_(i-1) ^rel) x_(i-1) ^rel * Δt ; y_i ^rel = y_(i-1) ^rel + D(-1+x_(i-1)
^rel) y_(i-1) ^rel * Δt
*/

  double x0, y0, A, B, C, D, dt;
  int ripetizioni;
  std::cout << "Inserisci lo stato iniziale x0 ed y0 : " << '\n';
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
        "I numeri A, B, C, D devono essere maggiori di zero"};
  }
  std::cout << "Inserisci il dt, ovvero l'intervallo temporale nel quale si "
               "vuole fare la "
               "simulazione. Sceglierlo dell'ordine di 0.001 : "
            << '\n';
  std::cin >> dt;
  if (dt <= 0) {
    throw std::runtime_error{
        " L'intervallo temporale deve essere maggiore di zero "};
  }
  std::cout << "Inserire le ripetizioni del dt per fare evolvere il sistema. "
               "La durata "
               " totale della simulazione sarà questo valore moltiplicato per "
               "il dt appena inserito. "
            << '\n';
  std::cin >> ripetizioni;

  return 0;
}
