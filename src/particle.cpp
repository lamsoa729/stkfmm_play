/**
 * @author      : alamson (alamson@$HOSTNAME)
 * @file        : particle
 * @created     : Monday Jun 07, 2021 17:03:48 EDT
 */

#include "particle.hpp"

Particle::Particle(parameters &params, int oid, double pos[3])
    : oid_(oid), rad_(params.particle_rad) {
    ZeroForce();
    calcDrag(params.viscosity);
    std::copy(pos, pos + 3, pos_);
}

void Particle::Integrate(double dt) {
    for (int i = 0; i < 3; ++i) {
        pos_[i] += (force_[i] / drag_coeff_) * dt;
    }
    ZeroForce();
}

