#include<iostream>
#include<algorithm>
#include<vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<long long> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> c[i] >> d[i];
    }
       
    for (int i = 0; i < n; i++)
    {
        int minID = -1;
        long long min = __LONG_LONG_MAX__;
        for (int j = 0; j < m; j++)
        {
            long long dist = std::abs(a[i] - c[j]) + std::abs(b[i] - d[j]);
     
            if (min > dist)
            {
                min = dist;
                minID = j + 1;
                
            }
        }

        std::cout << minID << "\n";
    }
}