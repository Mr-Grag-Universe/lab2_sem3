//
// Created by Stephan on 15.09.2022.
//
#include <iostream>
#include <cmath>

#include "CN_graph.h"

double CN_graph::slope_coefficient() {
    return this->k;
}

double CN_graph::free_member() {
    return this->a;
}

double CN_graph::extra_radius() {
    return this->l;
}


double CN_graph::y_from_x(double x) {
    return 0;
}

double CN_graph::radius_vector(double angle) {
    return this->l + this->a / (cos(angle)*this->k - sin(angle));
}

double CN_graph::radius_vector(std::pair<double, double> coord) {
    return std::sqrt(pow(coord.first, 2) + pow(coord.second, 2));
}