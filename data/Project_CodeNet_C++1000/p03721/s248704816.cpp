#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <utility>

bool sort_a(std::pair<long long, long long> a, std::pair<long long, long long> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    long long n;
    long long k;
    std::cin >> n >> k;
    std::vector<std::pair<long long, long long> > ab(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ab[i].first >> ab[i].second;
    }

    std::sort(ab.begin(), ab.end(), sort_a);

    long long sum = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        //std::cout << ab[i].first << " " << ab[i].second << std::endl;
        if((sum += ab[i].second) >= k) {
            ans = ab[i].first;
            break;
        }
    }

    std::cout << ans << std::endl;
}