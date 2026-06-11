/*
  Contest 065
  B - Trained?
  Rakesh Kumar --> 31/08/2020
b*/

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::vector<int> deep_maala(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int p = 0;
        std::cin >> p;
        deep_maala[i] = p;
    }

    int curr = 1, next = 0;
    int dabana = 0;
    while (1) {
        ++dabana;
        if (deep_maala[curr] == 2) {
            std::cout << dabana << std::endl;
            break;
        }
        if (deep_maala[curr] == 0) {
            std::cout << -1 << std::endl;
            break;
        }
        next = deep_maala[curr];
        deep_maala[curr] = 0;
        curr = next;
    }

    return 0;
}
