#include <iostream>

int main() {
    int n; std::cin >> n;
    int s = 1;
    bool inc = false, dec = false;
    int p; std::cin >> p;
    for (int i = 1; i < n; i ++) {
        int v; std::cin >> v;
        if (!inc && ! dec) {
            if (p < v) {
                inc = true;
            } else if (p > v) {
                dec = true;
            }
        } else if (inc) {
            if (p > v) {
                s++;
                inc = false;
            }
        } else if (dec) {
            if (p < v) {
                s++;
                dec =false;
            }
        }
        p = v;
    }

    std::cout << s  << std::endl;
    return 0;
}