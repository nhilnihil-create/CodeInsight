#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

void fact(int N, list<int> &V) {
    for (int i = 2; i*i <= N; i++) {
        while (N % i == 0) {
            V.emplace_back(i);
            N /= i;
        }
    }
    if (N != 1) V.emplace_back(N);
}

int main() {
    int N; cin >> N;
    map<int, int> M;
    ll MOD = (ll)pow(10,9) + 7;

    for (int i = 2; i <= N; i++) {
        list<int> V;
        V.clear();
        fact(i, V);
        if (V.empty()) M[i]++;
        else for (auto x : V) M[x]++;
    }

    ll res = 1;
    for (auto x : M) {
        res *= (x.second + 1);
        res %= MOD;
    }
    cout << res << endl;
}