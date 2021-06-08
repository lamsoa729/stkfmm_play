/**
 * @author      : alamson (alamson@$HOSTNAME)
 * @file        : particle
 * @created     : Monday Jun 07, 2021 16:43:54 EDT
 */

#ifndef PARTICLE_HPP

#define PARTICLE_HPP
#include <vector>

class Particle {
 public:
  Particle(double drag_coeff, double pos[3]);

  void Integrate(double dt);

  void ZeroForce();

  inline void addForce(double force[3]) {
    for (int i = 0; i < 3; ++i) {
      force_[i] += force[i];
    }
  }

  // virtual ~Particle();
  inline void PrintParticle() {
    printf(">  P%d : force = {%f, %f, %f} ; pos =  {%f, %f, %f} \n", oid_,
           force_[0], force_[1], force_[2], pos_[0], pos_[1], pos_[2]);
  }

 private:
  int oid_;
  double pos_[3];
  double force_[3];

  double drag_coeff_;
  /* private data */
};

#endif /* end of include guard PARTICLE_HPP */

