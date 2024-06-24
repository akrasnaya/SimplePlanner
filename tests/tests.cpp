#include "iostream"
#include "vector"
#include "assert.h"
#include "../include/CostMatrix.h"
#include "../include/planners.h"
#include "../include/utils.h"

using namespace utils;
using namespace planners;


/**
    * Функция, возвращающая итоговое минимальное значение от точки с индексом start до конца маршрута
    *
    * @param[out] минимальное значение от точки с индексом start до конца маршрута
    * @param[in] points - список точек, введенных с stdin
    * @param[in] start - индекс точки, начиная с которой необходимо построить кратчайший маршрут
    */
float calculate_min_time(std::vector<std::vector<int>>& points, int start) {

    std::vector<std::vector<int>> route = planners::create_route(points);
    CostMatrix time_heuristic(route);
    std::vector<std::vector<float>> time_cost_matrix = time_heuristic.create_time_cost_matrix();
    std::vector<float> min_time = planners::dijkstra_search(time_cost_matrix, start);
    return round(min_time.back(), 3);
}

void test_planner() {
    assert(calculate_min_time({{50, 50, 20}}) == 90.711);
    assert(calculate_min_time({{30, 30, 90}, {60, 60, 80}, {10, 90, 100}}) == 156.858);
    assert(calculate_min_time({{30, 30, 90}, {60, 60, 80}, {10, 90, 10}}) == 110.711);

};