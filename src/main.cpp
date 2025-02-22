#include "iostream"
#include "vector"
#include "fstream"
#include <Eigen/Dense>
#include "../include/json.hpp"
#include "../include/CostMatrix.h"
#include "../include/planners.h"
#include "../include/utils.h"
#include "visualization.cpp"

using namespace utils;
using namespace planners;
using json = nlohmann::json;


/**
    * Метод, который парсит json-config во внутреннюю структуру конфига utils::config и устанавливает параметры для
    * планеров
    *
    * @param[in] task_config - пустая структура
    */
void set_params(utils::config& task_config) {
    std::ifstream f("../config.json");
    json config_data = json::parse(f);

    task_config.max_fill_value = config_data.at("max_fill_value");
    task_config.field_size = config_data.at("field_size");
    task_config.speed = config_data.at("speed");
    task_config.seconds_to_load = config_data.at("seconds_to_load");
    task_config.start_ind = config_data.at("start_inds");

    planners::max_fill_value = task_config.max_fill_value;
    planners::field_size = task_config.field_size;
}

/**
    * Функция, возвращающая итоговое минимальное значение от точки с индексом start до конца маршрута
    *
    * @param[out] минимальное значение от точки с индексом start до конца маршрута
    * @param[in] points - список точек, введенных с stdin
    * @param[in] start - индекс точки, начиная с которой необходимо построить кратчайший маршрут
    */
std::vector<float> calculate_distances(const std::vector<Eigen::Vector3i>& points, const utils::config& task_config) {
    const std::vector<Eigen::Vector3i> route = planners::create_route(points);
    std::cout << "Маршрут: " << route.size() << std::endl;
    CostMatrix time_heuristic(route, task_config.speed, task_config.seconds_to_load, task_config.max_fill_value);
    Eigen::MatrixXf time_cost_matrix = time_heuristic.create_time_cost_matrix();
    std::cout << "Матрица эвристик: " << time_cost_matrix.rows() << "x" << time_cost_matrix.cols() << std::endl;
    std::vector<float> min_time = planners::dijkstra_search(time_cost_matrix, task_config.start_ind);
    return min_time;
}


int main() {
    utils::config task_config;
    set_params(task_config);

    int N;          // количество точек в маршруте
    std::cin >> N;

    while (N != 0) {
        std::vector<Eigen::Vector3i> points;
        points.reserve(N);
        for (int i = 0; i < N; ++i) {
            Eigen::Vector3i point;
            for (int j = 0; j < 3; ++j) {
                std::cin >> point[j];
            }
            points.emplace_back(point);
        }

        std::vector<float> distances = calculate_distances(points, task_config);
        std::cout << "Минимальное время: " << utils::round(distances.back(), 3) << std::endl;

        // Визуализаци
        visualizeDijkstra(points, distances);

        N -= 1;
    }

    return 0;
}
