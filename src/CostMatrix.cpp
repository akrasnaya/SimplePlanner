////
//// Created by Анастасия Красная on 23.06.2024.
////
//
//#include "CostMatrix.h"
//#include "utils.h"
//#include "vector"
//
//using namespace utils;
//
//class CostMatrix{
//    protected:
//    int speed = 2;
//    int seconds_to_load = 10;
//    int max_fill_value = 10000;
//
//    public:
//        std::vector<std::vector<int>> route;
//        std::vector<std::vector<int>> cost_matrix;
//        CostMatrix(std::vector<std::vector<int>> a) {
//            route = a;
//        }
//
//
//    // Функция для подсчета времени от каждой вершины до конца маршрута с учетом времени загрузки и штрафов
//// Возвращает матрицу стоимости по времени
//    std::vector<std::vector<int>> create_time_cost_matrix(std::vector<std::vector<int>>& route) {
//
//        for (int i = 0; i < route.size(); i++) {
//            int penalty = 0;
//            for (int j = 0; j < route.size(); j++) {
//                if (j > i) {
//                    time_graph[i][j] = time_dist(route[i], route[j], speed) + seconds_to_load + penalty;
//                    penalty += route[j][2];
//                }
//                else {
//
//                    time_graph[i][j] = max_fill_value;
//                }
//            }
//        }
//        return time_graph;
//    }
//
//
//};