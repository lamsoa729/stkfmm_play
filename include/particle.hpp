/**
 * @author      : alamson (alamson@$HOSTNAME)
 * @file        : particle
 * @created     : Monday Jun 07, 2021 16:43:54 EDT
 */

#ifndef PARTICLE_HPP

#define PARTICLE_HPP

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

#include "parameters.hpp"

class Particle {
 private:
  int oid_;
  double rad_;
  double drag_coeff_;
  double pos_[3];
  double force_[3];

  inline void calcDrag(double viscosity) {
    drag_coeff_ = viscosity * 6. * M_PI * rad_;
  }

 public:
  Particle(parameters& params, int oid, double pos[3]);

  void Integrate(double dt);

  // inline void ZeroForce() { std::fill(force_, force_ + 3, 0); }
  inline void ZeroForce() { std::fill(force_, force_ + 3, 0); }

  inline void setPos(double pos[3]) { std::copy(pos, pos + 3, pos_); }

  inline void addForce(double force[3]) {
    for (int i = 0; i < 3; ++i) {
      force_[i] += force[i];
    }
  }

  inline void PrintParticle() {
    printf(">  P%d : force = {%f, %f, %f} ; pos =  {%f, %f, %f} \n", oid_,
           force_[0], force_[1], force_[2], pos_[0], pos_[1], pos_[2]);
  }
};

#endif /* end of include guard PARTICLE_HPP */

