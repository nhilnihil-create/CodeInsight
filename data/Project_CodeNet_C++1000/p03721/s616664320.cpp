#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, K;
    cin >> N >> K;
    map<long long, long long> arr;
    for (long long i = 0; i < N; ++i) {
        long long a, b;
        cin >> a >> b;
        if (arr.count(a) == 0) {
            arr.insert(make_pair(a, 0));
        }
        arr[a] += b;
    }

    long long nth = 0;
    long long ans = 0;
    for (auto e : arr) {
        nth += e.second;
        if (nth >= K) {
            ans = e.first;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
