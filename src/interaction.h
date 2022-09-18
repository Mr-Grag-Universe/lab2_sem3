//
// Created by Stephan on 17.09.2022.
//

#ifndef LAB2_SEM3_INTERACTION_H
#define LAB2_SEM3_INTERACTION_H

#include "CN_graph.h"

CN_graph new_cn();

void new_a(CN_graph &cn);

void new_k(CN_graph &cn);

void new_l(CN_graph &cn);

void find_y_from_x(CN_graph &cn);

void find_y_from_angle(CN_graph &cn);

void find_radius_vector(CN_graph &cn);

void find_CR_in_CP_of_CN(CN_graph &cn);

void find_loop_area(CN_graph &cn);

void find_inflection_points(CN_graph &cn);

#endif //LAB2_SEM3_INTERACTION_H
