//
// Created by Stephan on 15.09.2022.
//
#include <iostream>
#include <cmath>

#include "CN_graph.h"

std::pair<double, double> approximate_calculation(double (*formula)(double, double));
std::vector<double> approximate_calculation(double (*formula)(double, double, double, double), double a, double k, double l, double ex) {
    std::vector<double> v;
    //double e = formula(-100, a, k, l);
    double delta = 10;
    bool go_away = false;
    for (long x = -100000+1; x < 100000; ++x) {
        double res = formula(x/1000, a, k, l);
        if (delta > std::abs(res-ex)) {
            v.pop_back();
            v.push_back(x/1000);
        } else {
            if (!go_away)
                v.push_back(0);
            go_away = true;
        }
        delta = std::abs(res-ex);
    }
    return v;
}

bool CN_graph::check_coords(std::pair<double, double> coord, double e) const {
    double x = coord.first;
    double y = coord.second;
    double A = atan(k);
    bool plus_l = std::abs((x*sin(A) - y*cos(A)) + cos(A)*a - l*(x*sin(A) - y*cos(A))/sqrt(x*x + y*y)) <= std::abs(e);
    bool minus_l = std::abs((x*sin(A) - y*cos(A)) + cos(A)*a + l*(x*sin(A) - y*cos(A))/sqrt(x*x + y*y)) <= std::abs(e);
    return plus_l || minus_l;
}

double CN_graph::slope_coefficient() const {
    return this->k;
}
double CN_graph::free_member() const {
    return this->a;
}
double CN_graph::extra_radius() const {
    return this->l;
}


void CN_graph::set_slope_coefficient(double sc) {
    this->k = sc;
}
void CN_graph::set_free_member(double fm) {
    this->a = fm;
}
void CN_graph::set_extra_radius(double er) {
    this->l = er;
}


double CN_graph::y_from_x(double x) const {
    if (this->k < 1000) {
        throw std::invalid_argument("we cannot calculate this without angle.");
    }
    if (this->k >= 1000)
        return std::sqrt(pow(x*l, 2) / pow(x - this->a, 2) - x*x);
    return 0;
}

double CN_graph::y_from_angle(double angle) const {
    return (this->a / (sin(angle) - this->k * cos(angle)) + this->l) * sin(angle);
}

double CN_graph::radius_vector(double angle) const {
    return this->l + this->a / (-cos(angle)*this->k + sin(angle));
}
double CN_graph::radius_vector(std::pair<double, double> coord) const {
    if (check_coords(coord, 0.0001))
        return std::sqrt(pow(coord.first, 2) + pow(coord.second, 2));
    throw std::invalid_argument("this coords do not below this graph");
}

std::vector<std::pair<std::string, double>> CN_graph::CR_in_CP_of_CN() const {
    std::vector<std::pair<std::string, double>> v;
    v.emplace_back("A", pow(a+l, 2)/l);
    v.emplace_back("B", pow(l-a, 2)/l);
    if (a <= l)
        v.emplace_back("C", l*sqrt(l*l - a*a)/(2*a));
    return v;
}

double CN_graph::loop_area() const {
    if (l < a)
        return 0;
    return a*sqrt(l*l - a*a) - 2*a*l*log((l+sqrt(l*l-a*a))/a) + l*l*acos(a/l);
}

double ip_formula(double x, double a, double k, double l) {
    return pow(x, 3) - 3*a*a*x + 2*a*(a*a - l*l);
}

double y_primal_formula(double x, double a, double k, double l) {
    return sqrt(l*l*x*x / pow((x-a), 2) - x*x);
}

std::vector<std::pair<double, double>> CN_graph::inflection_points() const {
    if (k != 0 && k < 1000)
        throw std::invalid_argument("we cannot find this points in such curve");
    std::vector<std::pair<double, double>> res;
    std::vector<double> v = approximate_calculation(ip_formula, a, k, l, 0);
    if (k >= 1000) {
        for (auto x: v) {
            res.emplace_back(x, y_primal_formula(x, a, k, l));
        }
    } else {
        for (auto x: v) {
            res.emplace_back(y_primal_formula(x, a, k, l), x);
        }
    }
    return res;
}

CN_graph CN_graph::input(std::istream & cin) {
    CN_graph cn;
    cin >> cn.a >> cn.k >> cn.l;
    return cn;
}
