#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int field_size = 100;
int speed = 2;
int seconds_to_load = 10;
int start_ind = 0;
int max_fill_value = 10000;

// Функция округления дробного числа var до n чисел после запятой
float round(float var, int n) {
    
    int util_num = ::pow(10, n);
    float value = (int)(var * util_num + .5);
    return (float)value / util_num;
}

// Функция вычисления индекса ближайшего непосещенного соседа для поиска Дийкстры
int get_closest_neighbour(vector<float> time_distances, vector<bool> visited) {

    int ind = 0;
    float min = max_fill_value;

    for (int i = 0; i < time_distances.size(); i++) {
        if (visited[i] == false && time_distances[i] < min) {
            min = time_distances[i];
            ind = i;
        }
    }
    return ind;
}

// Поиск Дийкстры по заполненной матрице значений времени точек от вершины (точки) с индексом start
vector<float> dijkstra_search(vector<vector<float>>& time_cost_matrix, int start) {

    vector<bool> visited (time_cost_matrix.size(), false);
    vector<float> time_distances (time_cost_matrix.size(), max_fill_value);
    vector<int> parent_nodes (time_cost_matrix.size(), 0);

    time_distances[start] = 0;
    parent_nodes[start] = -1;

    for (int g = 0; g < time_cost_matrix.size() - 1; g++) {
        int u = get_closest_neighbour(time_distances, visited);
        visited[u]= true;

        for (int v = 0; v < time_cost_matrix.size(); v++) {
            if (visited[v] == false && (time_distances[u] + time_cost_matrix[u][v]) <
            time_distances[v] && time_cost_matrix[u][v] != max_fill_value) {
                parent_nodes[v] = u;
                time_distances[v] = time_distances[u] + time_cost_matrix[u][v];
            }
        }

    }
    return time_distances;
}

// Функция для вычисления времени на проезд по прямой между двумя точками
float time_dist(vector<int> point1, vector<int> point2) {
    
    float dist = ::sqrt(::pow((point2[0] - point1[0]), 2) + ::pow((point2[1] - point1[1]), 2));
    return dist / speed;
}

// Функция для подсчета времени от каждой вершины до конца маршрута с учетом времени загрузки и штрафов
// Возвращает матрицу стоимости по времени
vector<vector<float>> create_time_cost_matrix(vector<vector<int>>& route) {
    vector<vector<float>> time_graph (route.size(), vector<float> (route.size()));
    
    for (int i = 0; i < time_graph.size(); i++) {
        int penalty = 0;
        for (int j = 0; j < time_graph[0].size(); j++) {
            if (j > i) {
                time_graph[i][j] = time_dist(route[i], route[j]) + seconds_to_load + penalty;
                penalty += route[j][2];
            }
            else {
                time_graph[i][j] = max_fill_value;
            }
        }
    }
    return time_graph;
}

// Функция, которая "оборачивает" список точек в маршрут - добавляет начало и конец маршрута
// возращает список всех точек маршрута
vector<vector<int>> create_route(vector<vector<int>>& points) {
    
    vector<int> start = {0, 0, 0};
    vector<int> finish = {field_size, field_size, 0};
    vector<vector<int>> route;
    
    route.push_back(start);
    for (auto point: points) {
        route.push_back(point);
    }
    route.push_back(finish);
    
    return route;
}

// Функция, возвращающая итоговое минимальное значение от точки с индексом start до конца маршрута
float calculate_min_time(vector<vector<int>>& points, int start) {
    
        vector<vector<int>> route = create_route(points);
        vector<vector<float>> time_cost_matrix = create_time_cost_matrix(route);
        vector<float> min_time = dijkstra_search(time_cost_matrix, start);
        return round(min_time.back(), 3);
}


int main() {
    int N;
    cin >> N;
    while (N != 0) {
        vector<vector<int>> points;
        for (int i = 0; i < N; i++) {
            vector<int> point;
            for (int j = 0; j < 3; j++) {
                int num;
                cin >> num;
                point.push_back(num);
            }
            points.push_back(point);
        }
        float min_time = calculate_min_time(points, start_ind);
        cout << min_time << endl;
        cin >> N;
    }
    return 0;
}
