#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

ll gao(ll x, ll y) {
    if (x <= y) return y - x;
    return x - y + 2;
}

int main() {
    ll x, y; cin >> x >> y;
    ll res = min({gao(x,y), gao(-x, y) + 1, gao(x, -y) + 1});
   
    cout << res << endl;
}