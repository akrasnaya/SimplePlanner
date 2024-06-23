//
// Created by Анастасия Красная on 23.06.2024.
//

#include "vector"
#include "CostMatrix.h"

namespace planners {

    int max_fill_value = 10000;     //величина максимального значения для заполнения
    int field_size = 100;           //размер поля


    /**
    * Функция, которая "оборачивает" список точек в маршрут - добавляет начало и конец маршрута
    *
    * @param[out] route - список всех точек маршрута, включая начало и конец
    * @param[in] points - список точек, введенных с stdin
    */
    std::vector<std::vector<int>> create_route(std::vector<std::vector<int>>& points) {

        std::vector<int> start = {0, 0, 0};
        std::vector<int> finish = {field_size, field_size, 0};
        std::vector<std::vector<int>> route;

        route.push_back(start);
        for (auto point: points) {
            route.push_back(point);
        }
        route.push_back(finish);

        return route;
    }

    /**
    * Функция вычисления индекса ближайшего непосещенного соседа для поиска Дийкстры
    *
    * @param[out] int ind - индекс ближайшего непосещенного соседа
    * @param[in] distance vector - список расстояний от начальной точки поиска до всех остальных
    * @param[in] visited - список посещенных точек в графе
    */
    int get_closest_neighbour(std::vector<float>& distance_vector, std::vector<bool>& visited) {

        int ind = 0;
        float min = max_fill_value;

        for (int i = 0; i < distance_vector.size(); i++) {
            if (visited[i] == false && distance_vector[i] < min) {
                min = distance_vector[i];
                ind = i;
            }
        }
        return ind;
    }

    /**
    * Поиск Дийкстры по заполненной матрице эвристик от вершины (точки) с индексом start
    *
    * @param[out] distance vector - список расстояний от начальной точки поиска до всех остальных
    * @param[in] cost_matrix - двумерная заполненная матрица эвристик
    * @param[in] start - индекс точки маршрута, с которой начинается поиск
    */
    std::vector<float> dijkstra_search(std::vector<std::vector<float>> cost_matrix, int start) {


        std::vector<bool> visited (cost_matrix.size(), false);
        std::vector<float> time_distances (cost_matrix.size(), max_fill_value);
        std::vector<int> parent_nodes (cost_matrix.size(), 0);

        time_distances[start] = 0;
        parent_nodes[start] = -1;

        for (int g = 0; g < cost_matrix.size() - 1; g++) {
            int u = get_closest_neighbour(time_distances, visited);
            visited[u]= true;

            for (int v = 0; v < cost_matrix.size(); v++) {
                if (visited[v] == false && (time_distances[u] + cost_matrix[u][v]) <
                                           time_distances[v] && cost_matrix[u][v] != max_fill_value) {
                    parent_nodes[v] = u;
                    time_distances[v] = time_distances[u] + cost_matrix[u][v];
                }
            }

        }
        return time_distances;
    }

}

