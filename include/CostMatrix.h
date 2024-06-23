//
// Created by Анастасия Красная on 23.06.2024.
//
#ifndef SIMPLEPLANNER_COSTMATRIX_H
#define SIMPLEPLANNER_COSTMATRIX_H

#include "utils.h"
#include "vector"
#include "fstream"
#include "json.hpp"

using namespace utils;
using json = nlohmann::json;

/**
 * Реализация матрицы эвристик для алгоритмов поиска/планирования
 */


// Загрузка необходимых полей из config
std::ifstream f("../config.json");
json config_data = json::parse(f);

class CostMatrix{
protected:
    int speed = config_data.at("speed");
    int seconds_to_load = config_data.at("seconds_to_load");
    int max_fill_value = config_data.at("max_fill_value");

public:
    std::vector<std::vector<int>> route;
    std::vector<std::vector<float>> cost_matrix; //
    CostMatrix(std::vector<std::vector<int>> a) {
        route = a; //единственное поле для конструктора - маршрут робота в виде списка точек
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
                    time_graph[i][j] = time_dist(route[i], route[j], speed) + seconds_to_load + penalty;
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
