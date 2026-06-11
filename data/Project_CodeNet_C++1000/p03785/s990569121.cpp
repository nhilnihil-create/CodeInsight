#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, C, K; cin >> N >> C >> K;
    vector<int> T(N);
    rep(i,N) cin >> T.at(i);
    sort(T.begin(), T.end());    
    int i = 0, p = 0, ws = 0;
    ll res = 0;
    while(i < N) {
        if (p == 0) ws = T[i];
        p++;
        if (i == N-1 || p == C || T[i+1] - ws > K) {
            res++;
            p = 0;
        }
        i++;
    }
    cout << res << endl;
}
