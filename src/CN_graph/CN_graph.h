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

    double y_from_x(double x);
    double radius_vector(double angle);
    double radius_vector(std::pair<double, double> coord);
};


#endif //LAB2_SEM3_CN_GRAPH_H
