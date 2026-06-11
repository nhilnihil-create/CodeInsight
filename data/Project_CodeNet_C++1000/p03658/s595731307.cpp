#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, res = 0;
    cin >> N >> K;
    int l[N];

    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }

    sort(l, l + N, greater<int>());

    for (int j = 0; j < K; j++) {
        res += l[j];
    }

    cout << res << endl;
}