#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll N, A, B;
vector<ll> X(100000);

int main() {
    cin >> N >> A >> B;
    ll cost = 0;
    ll walk;
    rep(i,N) {
        cin >> X.at(i);
        if (i > 0) {
            walk = abs(X[i] - X[i-1]) * A;
            cost += (walk < B) ? walk : B;
        }
    } 
    cout << cost << '\n';
}
