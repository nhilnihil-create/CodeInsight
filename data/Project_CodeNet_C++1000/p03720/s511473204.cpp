#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if(a[j] == i || b[j] == i) {
                cnt++;
            }
        }
        std::cout << cnt << "\n";
    }
}