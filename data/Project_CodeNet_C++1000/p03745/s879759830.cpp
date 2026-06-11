#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<int> V;
    int prev = INT32_MAX;
    rep(i,N) {
        int a; cin >> a;
        if (a == prev) continue;
        prev = a;
        V.push_back(a);
    }
    N = V.size();

    bool up;
    int i = 0;
    ll res = 0;
    while (i < N) {
        res++;
        if (i == N-1) break;
        up = (V[i] < V[i+1]);
        if (up) {
            while (i < N-1 && V[i] < V[i+1]) i++;
        } else {
            while (i < N-1 && V[i] > V[i+1]) i++;
        }
        i++;
    }
    cout << res << endl;
}
