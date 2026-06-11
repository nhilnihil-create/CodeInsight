#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N, M; cin >> N >> M;
    vector<ll> a(N, 0);
    vector<ll> b(N, 0);
    rep(i,M) {
        ll A, B; cin >> A >> B;
        if (A == 1) {
            a[B-1] = 1;
        }
        else if (B == 1) {
            a[A-1] = 1;
        }
        if (A == N) {
            b[B-1] = 1;
        }
        else if (B == N) {
            b[A-1] = 1;
        }
    }
    rep(i,N) {
        if (a[i] == 1 && b[i] == 1) {
                cout << "POSSIBLE" << endl;
                exit(0);
        }
    }
    cout << "IMPOSSIBLE" << endl;

}
