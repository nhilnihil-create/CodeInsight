#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mina = *std::min_element(a.begin(), a.end());
    int maxa = *std::max_element(a.begin(), a.end());

    int cost;
    int min = INT32_MAX;
    for (int i = mina; i <= maxa; i++)
    {
        cost = 0;
        for (int j = 0; j < n; j++) {
            cost += (a[j] - i) * (a[j] - i);
        }

        min = std::min(min, cost);
    }

    std::cout << min << "\n";
}