//
// Created by Анастасия Красная on 23.06.2024.
//

#include "../include/utils.h"
#include "../include/CostMatrix.h"
#include <Eigen/Dense>
#include <vector>
#include <array>
#include <iostream>

using namespace utils;
/**
 * Реализация матрицы эвристик для алгоритмов поиска/планирования
 */


/**
* Функция для подсчета эвристики по времени с учетом параметров задачи и штрафов
*
* @param[out] двумерная матрица стоимости по времени
*/
Eigen::MatrixXf CostMatrix::create_time_cost_matrix() const {
    Eigen::MatrixXf time_graph = Eigen::MatrixXf::Constant(route.size(), route.size(), max_fill_value);
    for (size_t i = 0; i < route.size(); ++i) {
        int penalty = 0;
        for (size_t j = i + 1; j < route.size(); ++j) {
            if (i >= time_graph.rows() || j >= time_graph.cols()) {
               std::cerr << "Index out of bounds: i=" << i << ", j=" << j << std::endl;
               continue;
           }
            time_graph(i, j) = utils::time_dist(route[i], route[j], speed) + seconds_to_load + penalty;
            penalty += route[j](2);
        }
    }
        return time_graph;
}
