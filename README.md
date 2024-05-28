Funkcja `bellman_ford` implementuje algorytm Bellmana-Forda, który jest używany do znalezienia najkrótszej ścieżki w grafie ważonym. Oto szczegółowe wyjaśnienie linijka po linijce:

1. Funkcja `bellman_ford` przyjmuje dwa argumenty: `start`, który jest punktem początkowym, oraz `adjacency_matrix`, która jest macierzą sąsiedztwa reprezentującą graf.

2. Najpierw, funkcja tworzy dwie listy: `dist` i `pred`. `dist` przechowuje najkrótsze odległości od punktu początkowego do wszystkich innych wierzchołków, a `pred` przechowuje poprzednik każdego wierzchołka na najkrótszej ścieżce.

3. Następnie, funkcja ustawia odległość do punktu początkowego na 0, ponieważ odległość od wierzchołka do samego siebie jest zawsze równa 0.

4. Następnie, funkcja przechodzi przez wszystkie wierzchołki grafu (oprócz punktu początkowego) `n-1` razy. Dla każdego wierzchołka `u`, funkcja sprawdza wszystkie jego sąsiadujące wierzchołki `v`.

5. Jeżeli odległość do wierzchołka `u` plus waga krawędzi z `u` do `v` jest mniejsza niż obecna odległość do `v`, to funkcja aktualizuje odległość do `v` i ustawia `u` jako poprzednika `v`.

6. Po przejściu przez wszystkie wierzchołki `n-1` razy, funkcja zwraca listy `dist` i `pred`.

Algorytm Bellmana-Forda działa poprzez relaksację krawędzi. Relaksacja krawędzi polega na aktualizacji odległości do wierzchołka docelowego, jeżeli znaleziono krótszą ścieżkę. Algorytm wykonuje relaksację dla wszystkich krawędzi `n-1` razy, gdzie `n` to liczba wierzchołków w grafie. Po `n-1` iteracjach, algorytm gwarantuje znalezienie najkrótszej ścieżki do wszystkich wierzchołków (o ile nie ma cykli o ujemnej wadze).