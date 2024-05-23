#include <vector>
#include <limits>
#include <iostream>

// Funkcja do wyznaczania najkrótszej ścieżki w grafie za pomocą algorytmu Bellmana-Forda
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

    // Sprawdzenie, czy istnieje cykl o ujemnej wadze
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
    // Przykładowy graf jako macierz sąsiedztwa
    std::vector<std::vector<int>> adjacency_matrix = {
            {0, 2, 0, 0, 1, 0},
            {2, 0, 3, 0, 4, 0},
            {0, 3, 0, 2, 0, 0},
            {0, 0, 2, 0, 2, 2},
            {1, 4, 0, 2, 0, 0},
            {0, 0, 0, 2, 0 ,0}
    };

    unsigned int start = 0;
    unsigned int wierzcholek = 0;


    std::cout << "Podaj wierzcholek startowy: ";
    std::cin >> start;
    start -= 1;
	
    std::cout << "Podaj do ktorego wierzcholka chcesz znalezc najkrotsza droge: ";
    std::cin >> wierzcholek;
    wierzcholek -= 1;

    // Wyznaczanie najkrótszej ścieżki od wierzchołka 0 do wszystkich pozostałych
    std::vector<int> dist = bellman_ford(start, adjacency_matrix);

    if(wierzcholek > dist.size() || wierzcholek < 0 || start > dist.size() || start < 0) {
        std::cout << "Nie ma takiego wierzcholka";
        return 1;
    }

    std::cout << "Najkrotsza sciezka od " << start+1 << " do " << wierzcholek+1 << ": " << dist[wierzcholek] << std::endl;

    return 0;
}