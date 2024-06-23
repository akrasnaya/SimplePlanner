//
// Created by Анастасия Красная on 23.06.2024.
//
#ifndef SIMPLEPLANNER_UTILS_H
#define SIMPLEPLANNER_UTILS_H

#include "vector"
#include "cmath"


namespace utils {
    // Функция округления дробного числа var до n чисел после запятой
    float round(float var, int n) {

        int util_num = std::pow(10, n);
        float value = (int)(var * util_num + .5);
        return (float)value / util_num;
    }


// Функция для вычисления времени на проезд по прямой между двумя точками
    float time_dist(std::vector<int> point1, std::vector<int> point2, float speed) {

        float dist = ::sqrt(::pow((point2[0] - point1[0]), 2) + ::pow((point2[1] - point1[1]), 2));
        return dist / speed;
    }
}

#endif

