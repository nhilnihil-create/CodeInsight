#include<iostream>
#include<algorithm>

int main () {
    int k, s;
    std::cin >> k >> s;

    long long ans = 0;
    for (int x = 0; x <= k; x++)
    {
        for (int y = 0; y <= k; y++) {
            int z = s - x - y;
            if(z >= 0 && z <= k) {
                ans++;
            }
        }
    }

    std::cout << ans << "\n";
}