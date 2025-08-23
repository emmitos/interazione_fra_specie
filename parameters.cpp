#include "parameters.hpp"
#include <stdexcept>
namespace sim {
SimulationParameters::SimulationParameters(double x0_, double y0_, double A_,
                                           double B_, double C_, double D_,
                                           double dt_)
    : x0{x0_}, y0{y0_}, A{A_}, B{B_}, C{C_}, D{D_}, dt{dt_} {
  if (x0 <= 0 || y0 <= 0) {
    throw std::runtime_error{
        "le densità iniziali delle prrde e predatori devono essere numeri "
        "reali maggiorni di zero"};
  }
  if (A <= 0 || B <= 0 || C <= 0 || D <= 0) {
    throw std::runtime_error{
        "I numeri A, B, C, D devono essere reali e maggiori di zero"};
  }
  if (dt <= 0) {
    throw std::runtime_error{
        " L'intervallo temporale deve essere valido e maggiore di zero "};
  }
}

RelativeParameters::RelativeParameters(double x0, double y0, double C, double D,
                                       double B, double A)
    : x_rel(x0 * C / D), y_rel(y0 * B / A) {}

} 