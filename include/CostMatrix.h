//
// Created by Анастасия Красная on 23.06.2024.
//
#pragma once

#include <utils.h>
#include <Eigen/Dense>
#include <vector>
#include <array>

/**
 * Реализация матрицы эвристик для алгоритмов поиска/планирования
 */

using namespace utils;

class CostMatrix{
protected:
    int speed;
    int seconds_to_load;
    int max_fill_value;

public:
    std::vector<Eigen::Vector3i> route;
    Eigen::MatrixXf cost_matrix; //
    CostMatrix(const std::vector<Eigen::Vector3i>& a, int b, int c, int d)
        : route(a), speed(b), seconds_to_load(c), max_fill_value(d) {}


    /**
    * Функция для подсчета эвристики по времени с учетом параметров задачи и штрафов
    *
    * @param[out] двумерная матрица стоимости по времени
    */
    Eigen::MatrixXf create_time_cost_matrix() const;


};
