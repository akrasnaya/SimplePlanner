//
// Created by Анастасия Красная on 23.06.2024.
//
#ifndef SIMPLEPLANNER_COSTMATRIX_H
#define SIMPLEPLANNER_COSTMATRIX_H

#include "../include/utils.h"
#include "vector"
#include "array"


/**
 * Реализация матрицы эвристик для алгоритмов поиска/планирования
 */


class CostMatrix{
protected:
    int speed;
    int seconds_to_load;
    int max_fill_value;

public:
    std::vector<std::array<int, 3>> route;
    std::vector<std::vector<float>> cost_matrix; //
    CostMatrix(std::vector<std::array<int, 3>> a, int b, int c, int d) {
        route = a; //маршрут робота в виде списка точек
        speed = b;
        seconds_to_load = c;
        max_fill_value = d;
    }


    /**
    * Функция для подсчета эвристики по времени с учетом параметров задачи и штрафов
    *
    * @param[out] двумерная матрица стоимости по времени
    */
    std::vector<std::vector<float>> create_time_cost_matrix() {
        std::vector<std::vector<float>> time_graph (route.size(), std::vector<float> (route.size()));
        for (int i = 0; i < route.size(); i++) {
            int penalty = 0;
            for (int j = 0; j < route.size(); j++) {
                if (j > i) {
                    time_graph[i][j] = utils::time_dist(route[i], route[j], speed) + seconds_to_load + penalty;
                    penalty += route[j][2];
                }
                else {

                    time_graph[i][j] = max_fill_value;
                }
            }
        }
        cost_matrix = time_graph;
        return cost_matrix;
    }


};

#endif
