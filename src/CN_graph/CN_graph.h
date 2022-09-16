//
// Created by Stephan on 15.09.2022.
//

#ifndef LAB2_SEM3_CN_GRAPH_H
#define LAB2_SEM3_CN_GRAPH_H

#include <algorithm>

class CN_graph {
private:
    double k;
    double a;
    double l;
public:
    CN_graph(double a, double k=0, double l=1) {
        this->k = k;
        this->a = a;
        this->l = l;
    }
    ~CN_graph() = default;

    double slope_coefficient();
    double free_member();
    double extra_radius();

    void set_slope_coefficient(double);
    void set_free_member(double);
    void set_extra_radius(double);

    double y_from_x(double x);
    double y_from_angle(double angle);
    double radius_vector(double angle);
    double radius_vector(std::pair<double, double> coord);
    std::vector<std::pair<std::string, double>> CR_in_CP_of_CN();
    double loop_area();
    std::vector<std::pair<double, double>> inflection_points();
};


#endif //LAB2_SEM3_CN_GRAPH_H
