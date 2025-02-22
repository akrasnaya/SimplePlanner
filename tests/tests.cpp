#define BOOST_TEST_MODULE SimplePlannerTests
#include <boost/test/included/unit_test.hpp>
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

float calculate_distances(const std::vector<Eigen::Vector3i>& points, const utils::config& task_config) {
    const std::vector<Eigen::Vector3i> route = planners::create_route(points);
    CostMatrix time_heuristic(route, task_config.speed, task_config.seconds_to_load, task_config.max_fill_value);
    Eigen::MatrixXf time_cost_matrix = time_heuristic.create_time_cost_matrix();
    std::vector<float> min_time = planners::dijkstra_search(time_cost_matrix, task_config.start_ind);
    return utils::round(min_time.back(), 3);
}

BOOST_AUTO_TEST_CASE(test_planner) {
    utils::config task_config;
    task_config.speed = 2;
    task_config.seconds_to_load = 10;
    task_config.max_fill_value = 1000;
    task_config.field_size = 100;
    task_config.start_ind = 0;

    BOOST_CHECK_CLOSE(calculate_distances({{50, 50, 20}}, task_config), 90.711, 0.001);
    BOOST_CHECK_CLOSE(calculate_distances({{30, 30, 90}, {60, 60, 80}, {10, 90, 100}}, task_config), 156.858, 0.001);
    BOOST_CHECK_CLOSE(calculate_distances({{30, 30, 90}, {60, 60, 80}, {10, 90, 10}}, task_config), 110.711, 0.001);
}