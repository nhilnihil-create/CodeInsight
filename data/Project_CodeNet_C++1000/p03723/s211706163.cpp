#include <iostream>
#include <set>

int main() {
    int a, b, c; std::cin >> a >> b >> c;
    std::set<std::tuple<int, int, int>> memo;

    int cnt = 0;

    while (true) {
        if ((a%2 == 1) || (b%2 == 1) || (c%2 == 1)) {
            break;
        }
        memo.insert(std::make_tuple(a, b, c));
        cnt++;
        int na = (b + c) / 2;
        int nb = (c + a) / 2;
        int nc = (a + b) / 2;
        if (memo.find(std::make_tuple(na, nb, nc)) != memo.end()) {
            std::cout << -1 << std::endl;
            return 0;
        }
        a = na; b = nb; c = nc;
    }

    std::cout << cnt << std::endl;
    return 0;
}