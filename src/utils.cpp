//
// Created by Анастасия Красная on 23.06.2024.
//
#include "../include/utils.h"
#include "vector"
#include "cmath"
#include <Eigen/Dense>

namespace utils {

    /**
    * Функция округления дробного числа var до n чисел после запятой
    *
    * @param[out] округленное дробное числа var до n чисел после запятой
    * @param[in] var - дробное число
    * @param[in] n - количество цифр после запятой
    */
    float round(float var, int n) {

        int util_num = std::pow(10, n);
        float value = (int)(var * util_num + .5);
        return (float)value / util_num;
    }


    /**
    * Функция для вычисления времени на проезд по прямой между двумя точками point1 и point2 со скоростью speed
    *
    * @param[out] время на проезд по прямой между двумя точками point1 и point2 со скоростью speed
    * @param[in] point1 - начальная точка
    * @param[in] point2 - конечная точка
    * @param[in] speed - скорость робота
    */
    float time_dist(const Eigen::Vector3i& point1, const Eigen::Vector3i& point2, float speed) {

        float dist = (point2 - point1).norm();
        return dist / speed;
    }
}



