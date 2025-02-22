//
// Created by Анастасия Красная on 23.06.2024.
//
#ifndef SIMPLEPLANNER_UTILS_H
#define SIMPLEPLANNER_UTILS_H

#include "vector"
#include "cmath"
#include "array"
#include <Eigen/Dense>

namespace utils {

    /**
    * Структура для хранения конфига
    */
    struct config {
        int max_fill_value;
        int field_size;
        int speed;
        int seconds_to_load;
        int start_ind;
    };

    /**
    * Функция округления дробного числа var до n чисел после запятой
    *
    * @param[out] округленное дробное числа var до n чисел после запятой
    * @param[in] var - дробное число
    * @param[in] n - количество цифр после запятой
    */
    float round(float var, int n);


    /**
    * Функция для вычисления времени на проезд по прямой между двумя точками point1 и point2 со скоростью speed
    *
    * @param[out] время на проезд по прямой между двумя точками point1 и point2 со скоростью speed
    * @param[in] point1 - начальная точка
    * @param[in] point2 - конечная точка
    * @param[in] speed - скорость робота
    */
    float time_dist(const Eigen::Vector3i& point1, const Eigen::Vector3i& point2, float speed);
}

#endif

