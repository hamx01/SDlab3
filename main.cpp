#include <vector>
#include <limits>
#include <iostream>

std::vector<int> bellman_ford(unsigned int start, const std::vector<std::vector<int>>& adjacency_matrix) {
    int n = (int)adjacency_matrix.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (adjacency_matrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + adjacency_matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjacency_matrix[u][v];
                }
            }
        }
    }

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (adjacency_matrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + adjacency_matrix[u][v] < dist[v]) {
                throw std::runtime_error("Graf zawiera cykl o ujemnej wadze");
            }
        }
    }

    return dist;
}

int main() {
    std::vector<std::vector<int>> adjacency_matrix = {
            {0, 2, 0, 0, 1, 0},
            {2, 0, 3, 0, 4, 0},
            {0, 3, 0, 2, 0, 0},
            {0, 0, 2, 0, 2, 2},
            {1, 4, 0, 2, 0, 0},
            {0, 0, 0, 2, 0 ,0}
    };

    unsigned int start = 0;

    std::cout << "Podaj wierzcholek startowy: ";
    std::cin >> start;
    start -= 1;

    std::vector<int> dist = bellman_ford(start, adjacency_matrix);

    for(int i = 0; i < dist.size(); i++) {
        if(i != start) {
            std::cout << "Najkrotsza sciezka od " << start+1 << " do " << i+1 << ": " << dist[i] << std::endl;
        } else {
            std::cout << "Najkrotsza sciezka od " << start+1 << " do " << i+1 << ": 0" << std::endl;
        }
    }

    return 0;
}