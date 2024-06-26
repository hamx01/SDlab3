#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> znajdz_droge(unsigned int start, const std::vector<std::vector<int>>& macierz_sasiedztwa) {
    int n = (int)macierz_sasiedztwa.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<int> pred(n, -1);
    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (macierz_sasiedztwa[u][v] != 0 &&
                dist[u] != std::numeric_limits<int>::max() &&
                dist[u] + macierz_sasiedztwa[u][v] < dist[v])
                {
                    dist[v] = dist[u] + macierz_sasiedztwa[u][v];
                    pred[v] = u;
                }
            }
        }
    }
    return {dist, pred};
}

std::vector<int> zapisz_sciezke(int end, const std::vector<int>& pred) {
    std::vector<int> path;
    for(int v = end; v != -1; v = pred[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    std::vector<std::vector<int>> macierz_sasiedztwa = {
          // 1  2  3  4  5  6  7  8  9 10 11 12 13
            {0, 2, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
            {2, 0, 0, 0, 3, 2, 4, 0, 0, 0, 0, 0, 0}, // 2
            {4, 0, 0, 0, 2, 8, 1, 0, 0, 0, 0, 0, 0}, // 3
            {1, 0, 0, 0, 7, 4, 6, 0, 0, 0, 0, 0, 0}, // 4
            {0, 3, 2, 7, 0, 0, 0, 2, 4, 0, 0, 0, 0}, // 5
            {0, 2, 8, 4, 0, 0, 0, 3, 7, 0, 0, 0, 0}, // 6
            {0, 4, 1, 6, 0, 0, 0, 2, 5, 0, 0, 0, 0}, // 7
            {0, 0, 0, 0, 2, 3, 2, 0, 0, 6, 5, 9, 0}, // 8
            {0, 0, 0, 0, 4, 7, 5, 0, 0, 5, 1, 7, 0}, // 9
            {0, 0, 0, 0, 0, 0, 0, 6, 5, 0, 0, 0, 2}, // 10
            {0, 0, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 4}, // 11
            {0, 0, 0, 0, 0, 0, 0, 9, 7, 0, 0, 0, 2}, // 12
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 2, 0}  // 13
    };

    unsigned int n = macierz_sasiedztwa.size();

    unsigned int start = 0;

    std::cout << "Algorytm wyszukiwania najkrotszej sciezki w grafie nieskierowanym\n";
    std::cout << "Podaj wierzcholek startowy(1-" << n << "):";
    std::cin >> start;
    start -= 1;

    std::cout << "Podaj wierzcholek koncowy:";
    unsigned int end;
    std::cin >> end;
    end -= 1;

    if(start >= n || end >= n) {
        std::cout << "Podano zly wierzcholek" << std::endl;
        system("pause");
        return 1;
    }

    auto [dist, pred] = znajdz_droge(start, macierz_sasiedztwa);

    std::cout << "-----------------------------------------------------------" << std::endl;
        if(end != start) {
            std::cout << "Optymalna traektoria sterowan od " << start+1 << " do " << end+1 << " wynosi: ";
            std::vector<int> path = zapisz_sciezke(int(end), pred);
            for(int v : path) {
                std::cout << v+1 << " ";
            }
            std::cout << std::endl;
            std::cout << "Wskaznik jakosci J: " << dist[end] << std::endl;
            std::cout << "-----------------------------------------------------------" << std::endl;
            system("pause");
        } else {
            std::cout << "Optymalna traektoria sterowan od " << start+1 << " do " << end+1 << " wynosi: " << start+1 << std::endl;
            std::cout << "Wskaznik jakosci J: " << start+1 << std::endl;
            std::cout << "-----------------------------------------------------------" << std::endl;
            system("pause");
        }

    return 0;
}