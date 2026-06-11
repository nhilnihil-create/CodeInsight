#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long N;
    cin >> N;
    vector<long> a(N);
    for(auto& i : a)cin >> i;

    long t = accumulate(a.begin(), a.end(), 0L);
    auto k = N * (N + 1) / 2;
    if(t % k != 0 || !(t /= k))return 0 & puts("NO");
    vector<long> b(N);
    b[N - 1] = a[N - 1] - a[0] + t;
    for(unsigned long i = 1; i < N; ++i)b[i - 1] = a[i - 1] - a[i] + t;

    for(const auto i : b)if(i < 0 || i % N != 0)return 0 & puts("NO");
    puts("YES");
    return 0;
}