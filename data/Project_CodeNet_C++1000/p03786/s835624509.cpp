#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

// naive
ll solve(int N, map<int,int>& M) {
    int res = 0;
    ll wa = 0;
    for (auto x = M.begin(); x != M.end(); x++) {
        wa += x->first * x->second;
        auto n = next(x);
        if (n == M.end()) { // right next is not there
            res += x->second;
            break;
        }
        ll cur = wa; // You can eat every smaller animals
        while (n != M.end()) {
            if (cur * 2 >= n->first) cur += n->first;
            else goto LOOP;
            n = next(n);
        }
        res += x->second;
LOOP: ;
    }
    return res;
}

// right answer
ll solve2(int N, map<int,int>& M) {
    int res = 0;
    ll wa = 0;
    for (auto x : M) wa += (ll)x.first * x.second;

    for (auto x = M.rbegin(); x != M.rend(); x++) {
        wa -= (ll)x->first * x->second;
        res += x->second;
        if (wa *2 < x->first) break;
    }
    return res;
}

// editorial
ll solve3(int N, map<int,int>& M) {
    ll wa = 0;
    ll cnt = 0;
    ll ma = 0;
    for (auto x = M.begin(); x != M.end(); x++) {
        ll k = x->first, v = x->second;
        cnt += v;
        wa += (ll) k * v;
        auto n = next(x);
        if (n == M.end()) break;
        if (2 * wa < n->first) {
            if (ma < cnt) ma = cnt;
            continue;
        }
    }
    return N - ma;
}

int main() {
    int N; cin >> N;
    map<int, int> M;
    rep(i,N) {
        int a; cin >> a;
        M[a]++;
    }

    cout << solve3(N, M) << endl;
}
