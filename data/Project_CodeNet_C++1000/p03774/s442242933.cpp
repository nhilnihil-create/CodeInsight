#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

struct Posi {
    ll x;
    ll y;
};

int main()
{
    ll N, M; cin >> N >> M;
    struct Posi P[N];
    struct Posi C[M];
 
    rep(i, N) {
        ll a, b; cin >> a >> b;
        P[i].x = a;
        P[i].y = b;
    }
    rep(i, M) {
        ll c, d; cin >> c >> d;
        C[i].x = c;
        C[i].y = d;
    }
    vector<ll> ans;
    rep(i, N) {
        ll min = -1;
        ll num = 0;
        rep(j, M) {
            ll tmp = abs(P[i].x - C[j].x) + abs(P[i].y - C[j].y);
            if (min == -1) {
                min = tmp; num = j; 
            }
            else if (min > tmp) {
                min = tmp; num = j;
            }
        }
        ans.push_back(num+1);
    }

    rep(i,N) {
        cout << ans[i] << endl;
    }

}
