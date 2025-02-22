#pragma once

#include <vector>
#include <Eigen/Dense>

namespace planners {

    inline int max_fill_value;
    inline int field_size;


    /**
    * Функция, которая "оборачивает" список точек в маршрут - добавляет начало и конец маршрута
    *
    * @param[out] route - список всех точек маршрута, включая начало и конец
    * @param[in] points - список точек, введенных с stdin
    */
    std::vector<Eigen::Vector3i> create_route(const std::vector<Eigen::Vector3i>& points);


    /**
    * Функция вычисления индекса ближайшего непосещенного соседа для поиска Дийкстры
    *
    * @param[out] int ind - индекс ближайшего непосещенного соседа
    * @param[in] distance vector - список расстояний от начальной точки поиска до всех остальных
    * @param[in] visited - список посещенных точек в графе
    */
    int get_closest_neighbour(std::vector<float> distance_vector, std::vector<bool> visited);



    /**
    * Поиск Дийкстры по заполненной матрице эвристик от вершины (точки) с индексом start
    *
    * @param[out] distance vector - список расстояний от начальной точки поиска до всех остальных
    * @param[in] cost_matrix - двумерная заполненная матрица эвристик
    * @param[in] start - индекс точки маршрута, с которой начинается поиск
    */
    std::vector<float> dijkstra_search(Eigen::MatrixXf& cost_matrix, int start);

}



