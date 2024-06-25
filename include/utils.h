//
// Created by Анастасия Красная on 23.06.2024.
//
#ifndef SIMPLEPLANNER_UTILS_H
#define SIMPLEPLANNER_UTILS_H

#include "vector"
#include "cmath"
#include "array"


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
    float time_dist(std::array<int, 3> point1, std::array<int, 3> point2, float speed) {

        float dist = ::sqrt(::pow((point2[0] - point1[0]), 2) + ::pow((point2[1] - point1[1]), 2));
        return dist / speed;
    }
}

#endif

