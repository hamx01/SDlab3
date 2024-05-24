#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> bellman_ford(unsigned int start, const std::vector<std::vector<int>>& adjacency_matrix) {
    int n = (int)adjacency_matrix.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<int> pred(n, -1);
    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (adjacency_matrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + adjacency_matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjacency_matrix[u][v];
                    pred[v] = u;
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

    return {dist, pred};
}

std::vector<int> reconstruct_path(int start, int end, const std::vector<int>& pred) {
    std::vector<int> path;
    for(int v = end; v != -1; v = pred[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    std::vector<std::vector<int>> adjacency_matrix = {
            {0, 2, 0, 0, 1, 0},
            {2, 0, 3, 0, 4, 0},
            {0, 3, 0, 1, 0, 0},
            {0, 0, 1, 0, 2, 2},
            {1, 4, 0, 2, 0, 0},
            {0, 0, 0, 2, 0, 0}
    };

    unsigned int start = 0;

    std::cout << "Algorytm wyszukiwania najkrotszej sciezki w grafie nieskierowanym\n";
    std::cout << "Podaj wierzcholek startowy:";
    std::cin >> start;
    start -= 1;

    auto [dist, pred] = bellman_ford(start, adjacency_matrix);

    std::cout << "-----------------------------------------------------------" << std::endl;
    for(int i = 0; i < dist.size(); i++) {
        if(i != start) {
            std::cout << "Optymalna traektoria sterowan od " << start+1 << " do " << i+1 << " wynosi: ";
            auto path = reconstruct_path(start, i, pred);
            for(int v : path) {
                std::cout << v+1 << " ";
            }
            std::cout << std::endl;
            std::cout << "Wskaznik jakosci J: " << dist[i] << std::endl;
            std::cout << "-----------------------------------------------------------" << std::endl;
        } else {
//            std::cout << "-----------------------------------------------------------" << std::endl;
            std::cout << "Optymalna traektoria sterowan od " << start+1 << " do " << i+1 << " wynosi: " << start+1 << std::endl;
            std::cout << "Wskaznik jakosci J: " << start+1 << std::endl;
            std::cout << "-----------------------------------------------------------" << std::endl;
        }
    }

    return 0;
}