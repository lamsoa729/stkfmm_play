/**
 * @author      : alamson (alamson@$HOSTNAME)
 * @file        : particle
 * @created     : Monday Jun 07, 2021 17:03:48 EDT
 */

#include "particle.hpp"

Particle::Particle(double drag_coeff, double pos[3])
    : oid_(1), drag_coeff_(drag_coeff) {
    ZeroForce();
    std::copy(pos, pos + 3, pos_);
}

void Particle::Integrate(double dt) {
    for (int i = 0; i < 3; ++i) {
        pos_[i] += (force_[i] / drag_coeff_) * dt;
    }
    ZeroForce();
}

void Particle::ZeroForce() { std::fill(force_, force_ + 3, 0); }

