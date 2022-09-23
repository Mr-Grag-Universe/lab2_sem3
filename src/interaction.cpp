//
// Created by Stephan on 17.09.2022.
//
#include <iostream>


#include "interaction.h"
#include "CN_graph.h"

CN_graph new_cn() {
    double a{}, k{}, l{};
    std::cin >> a >> k >> l;
    CN_graph cn(a, k, l);
    return cn;
}

void new_a(CN_graph &cn) {
    double a{};
    std::cout << "enter new a (free member): ";
    std::cin >> a;
    cn.set_free_member(a);
}
void new_k(CN_graph &cn) {
    double k{};
    std::cout << "enter new k (slope coefficient): ";
    std::cin >> k;
    cn.set_slope_coefficient(k);
}
void new_l(CN_graph &cn) {
    double l{};
    std::cout << "enter new l (extra radius): ";
    std::cin >> l;
    cn.set_extra_radius(l);
}

void find_y_from_x(CN_graph &cn) {
    if (cn.slope_coefficient() < 1000) {
        std::cout << "we cannot do this now" << std::endl;
        return;
    }

    double x{};
    std::cout << "x: ";
    std::cin >> x;
    try {
        std::cout << "y: "<< cn.y_from_x(x) << std::endl;
    } catch (...) {
        throw std::runtime_error("something wrong in finding y from x");
    }
}
void find_y_from_angle(CN_graph &cn) {
    double angle{};
    std::cout << "angle: ";
    std::cin >> angle;
    try {
        std::cout << "y: "<< cn.y_from_angle(angle) << std::endl;
    } catch (...) {
        throw std::runtime_error("something wrong in finding y from angle");
    }
}

void find_radius_vector(CN_graph &cn) {
    int chose_angle_coords = 0;
    std::cout << "do you have angle or coords of point\n1 - angle\n2 - coords" << std::endl;
    while (chose_angle_coords < 1 || chose_angle_coords > 2)
        std::cin >> chose_angle_coords;
    try {
        if (chose_angle_coords == 1) {
            double angle{};
            std::cout << "angle: ";
            std::cin >> angle;
            std::cout << "radius vector: "<< cn.radius_vector(angle) << std::endl;
        } else if (chose_angle_coords == 2) {
            std::pair<double, double> coords;
            std::cout << "x: ";
            std::cin >> coords.first;
            std::cout << "y: ";
            std::cin >> coords.second;

            std::cout << "radius vector: "<< cn.radius_vector(coords) << std::endl;
        }
    } catch (...) {
        throw std::runtime_error("something wrong in finding radius vector");
    }
}

void find_CR_in_CP_of_CN(CN_graph &cn) {
    std::cout << "CR in CP of CN\n";
    std::vector<std::pair<std::string, double>> v;
    try {
        v = cn.CR_in_CP_of_CN();
    } catch (...) {
        throw std::runtime_error("something wrong in finding y character points.");
    }
    for (const auto& el: v)
        std::cout << el.first << " " << el.second << std::endl;
}

void find_loop_area(CN_graph &cn) {
    std::cout << "loop area: " << cn.loop_area() << std::endl;
}

void find_inflection_points(CN_graph &cn) {
    if (cn.slope_coefficient() < 1000) {
        std::cout << "we cannot do this now" << std::endl;
        return;
    }

    std::cout << "inflection points of this CN are:\n";
    std::vector<std::pair<double, double>> v;
    try {
        v = cn.inflection_points();
    } catch (...) {
        throw std::runtime_error("something wrong in finding inflection points");
    }
    for (auto el: v)
        std::cout << el.first << " " << el.second << std::endl;
}