/**
 * @author      : alamson (alamson@$HOSTNAME)
 * @file        : main
 * @created     : Tuesday Jun 01, 2021 11:32:23 EDT
 */

#include <iostream>

#include "parameters.hpp"
#include "particle.hpp"

parameters make_params() {
    parameters params;
    params.dt = .0001;
    std::fill(params.sides, params.sides + 3, 5.);
    params.viscosity = 1.;
    params.particle_rad = 1.;

    return params;
}

int main() {
    parameters params = make_params();
    double pos[3] = {0, 0, 0};
    Particle p1(params, 1, pos);
    double force[3] = {1, 0, 0};
    p1.PrintParticle();
    p1.addForce(force);
    p1.Integrate(params.dt);
    p1.PrintParticle();

    // std::vector<Particle> particles;
    std::cout << "Hello world!" << std::endl;
    return 0;
}

