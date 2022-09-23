//
// Created by Stephan on 15.09.2022.
//

#ifndef LAB2_SEM3_CN_GRAPH_H
#define LAB2_SEM3_CN_GRAPH_H

#include <algorithm>
#include <vector>

typedef enum Funcs{
    EXIT,
    NEW_CN,
    NEW_A,
    NEW_K,
    NEW_L,
    Y_FROM_X,
    Y_FROM_ANGLE,
    RADIUS_VECTOR,
    CURVATURE_RADIUS,
    LOOP_AREA,
    INFLECTION_POINTS,
} Funcs;

class CN_graph {
private:
    double a;
    double k;
    double l;
public:
    CN_graph(double a, double k = 0, double l = 1) {
        this->k = k;
        this->a = a;
        this->l = l;
    }

    CN_graph() {
        this->k = 0;
        this->a = 0;
        this->l = 0;
    }

    ~CN_graph() = default;

    void set_slope_coefficient(double);

    void set_free_member(double);

    void set_extra_radius(double);

    static CN_graph input(std::istream & cin);

    [[nodiscard]] bool check_coords(std::pair<double, double> coord, double e) const;

    [[nodiscard]] double slope_coefficient() const;

    [[nodiscard]] double free_member() const;

    [[nodiscard]] double extra_radius() const;

    [[nodiscard]] double y_from_x(double x) const;

    [[nodiscard]] double y_from_angle(double angle) const;

    [[nodiscard]] double radius_vector(double angle) const;

    [[nodiscard]] double radius_vector(std::pair<double, double> coord) const;

    [[nodiscard]] std::vector<std::pair<std::string, double>> CR_in_CP_of_CN() const;

    [[nodiscard]] double loop_area() const;

    [[nodiscard]] std::vector<std::pair<double, double>> inflection_points() const;

    void plot(int argc, char* argv[]);
};


#endif //LAB2_SEM3_CN_GRAPH_H
