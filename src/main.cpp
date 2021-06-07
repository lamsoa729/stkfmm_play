/**
 * @author      : alamson (alamson@$HOSTNAME)
 * @file        : main
 * @created     : Tuesday Jun 01, 2021 11:32:23 EDT
 */

#include <iostream>

#include "particle.hpp"

int main() {
    double pos[3] = {0, 0, 0};
    Particle p1(1., pos);
    p1.PrintParticle();

    // std::vector<Particle> particles;
    std::cout << "Hello world!" << std::endl;
    return 0;
}

