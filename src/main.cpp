#include "iostream"
#include "vector"
#include "fstream"
#include "../include/json.hpp"
#include "../include/CostMatrix.h"
#include "../include/planners.h"
#include "../include/utils.h"

using namespace utils;
using namespace planners;
using json = nlohmann::json;


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


int main() {
    std::ifstream f("../config.json");
    json config_data = json::parse(f);
    int N;
    std::cin >> N;
    while (N != 0) {
        std::vector<std::vector<int>> points;
        for (int i = 0; i < N; i++) {
            std::vector<int> point;
            for (int j = 0; j < config_data.at("num_of_point_params"); j++) {
                int num;
                std::cin >> num;
                point.push_back(num);
            }
            points.push_back(point);
        }
        float min_time = calculate_min_time(points, config_data.at("start_inds"));
        std::cout << min_time << std::endl;
        std::cin >> N;
    }
    return 0;
}
