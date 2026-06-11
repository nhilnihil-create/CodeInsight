#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> S(N+1, 0);
    vector<long long> PS(N+1, 0);
    for(int i=1; i<=N; ++i) {
        long long a;
        cin >> a;
        S[i] = S[i - 1] + a;
        PS[i] = PS[i - 1];
        if(a > 0) PS[i] += a;
    }

    long long res = -1001001001001001001;
    for(int i=1; i+K-1<=N; ++i) {
        long long tmp = PS[i - 1] + (PS[N] - PS[i + K - 1]);
        if(S[i + K - 1] - S[i - 1] > 0) tmp += S[i + K - 1] - S[i - 1];
        res = max(res, tmp);
    }

    cout << res << endl;
}