#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::unordered_map<char, int> d;
    ++d[a]; ++d[b]; ++d[c];
    if (d[5] == 2 && d[7] == 1)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    return 0;
}
