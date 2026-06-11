#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, cnt = 0;
    cin >> N >> K;
    vector<long long> vec(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    for (auto i = 0; i < vec.size(); i++) {
        cnt += min((K - vec[i]) * 2, vec[i] * 2);
    }

    cout << cnt << endl;
}