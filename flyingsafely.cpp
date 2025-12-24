#include <iostream>
#include <vector>

int find_n_pilots(int cities);

int main() {
    int cases, cities, routes;
    std::cin >> cases;
    std::vector<int> res;

    for (int i = 0; i < cases; i++) {
        std::cin >> cities;
        std::cin >> routes;
        int a, b;
        for (int j = 0; j < routes; j++) {
            std::cin >> a;
            std::cin >> b;
        }
        res.push_back(find_n_pilots(cities));
    }

    for (int out : res) {
        std::cout << out << "\n";
    }
    return 0;
}

int find_n_pilots(int cities) {
    // Amount of edges in MST is always n - 1
    if (cities < 0) return 0;
    return cities - 1;
}