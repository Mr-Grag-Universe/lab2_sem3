//
// Created by Stephan on 15.09.2022.
//
#include <iostream>
#include <cmath>
#include "CN_graph.h"
#include "interaction.h"

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

bool execute_command(Funcs id, CN_graph &cn) {
    switch (id) {
        case EXIT:
            return false;
        case NEW_CN:
            cn = new_cn();
            return true;
        case NEW_A:
            new_a(cn);
            return true;
        case NEW_K:
            new_k(cn);
            return true;
        case NEW_L:
            new_l(cn);
            return true;
        case Y_FROM_X:
            find_y_from_x(cn);
            return true;
        case Y_FROM_ANGLE:
            find_y_from_angle(cn);
            return true;
        case RADIUS_VECTOR:
            find_radius_vector(cn);
            return true;
        case CURVATURE_RADIUS:
            find_CR_in_CP_of_CN(cn);
            return true;
        case LOOP_AREA:
            find_loop_area(cn);
            return true;
        case INFLECTION_POINTS:
            find_inflection_points(cn);
            return true;
        default:
            return true;
    }
}

void print_instruction() {
    std::cout << "0 - exit" << std::endl;
    std::cout << "1 - enter new cn" << std::endl;
    std::cout << "2 - enter new a" << std::endl;
    std::cout << "3 - enter new k" << std::endl;
    std::cout << "4 - enter new l" << std::endl;
    std::cout << "5 - find y from x (*)" << std::endl;
    std::cout << "6 - find y from angle" << std::endl;
    std::cout << "7 - find radius vector to point or from angle" << std::endl;
    std::cout << "8 - find radius of curvature for some points of cn" << std::endl;
    std::cout << "9 - find loop area" << std::endl;
    std::cout << "10 - find points of inflection for cn" << std::endl;
    std::cout << "11" << std::endl;
    std::cout << "12" << std::endl;
}

int main() {
    CN_graph cn = new_cn();
    Funcs command_id = EXIT;
    print_instruction();
    do {
        std::cout << "id of command: ";
        std::cin >> reinterpret_cast<unsigned long long int &>(command_id);
    } while (execute_command(command_id, cn));
}