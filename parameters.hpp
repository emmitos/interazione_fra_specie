#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP
namespace sim {
class SimulationParameters {
 public:
  const double x0, y0;
  const double A, B, C, D;
  const double dt;

  SimulationParameters(double x0_, double y0_, double A_, double B_, double C_,
                       double D_, double dt_);
};
class RelativeParameters {
 public:
  double x_rel;
  double y_rel;

  RelativeParameters(double x0, double y0, double C, double D, double B,
                     double A);
};
}
#endif