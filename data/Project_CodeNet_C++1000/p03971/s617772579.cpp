#include <bits/stdc++.h>

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a, b;
    std::string s;

    std::cin >> n >> a >> b >> s;

    int qualified = 0;
    int foreign = 0;

    for (char &c : s) {
        if (c == 'c') {
            goto No;
        }
        else if (c == 'a') {
            if (qualified < a + b) {
                ++qualified;
                goto Yes;
            }
        }
        else {
            if (qualified < a + b && foreign < b) {
                ++foreign;
                ++qualified;
                goto Yes;
            }
        }

        No:
            std::cout << "No\n";
            continue;
        Yes:
            std::cout << "Yes\n";
    }

    return 0;
}