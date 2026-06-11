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
    vector<ll> Px(N, 0);
    vector<ll> Py(N, 0);
    struct Posi C[M];
    vector<ll> Cx(M, 0);
    vector<ll> Cy(M, 0);

    rep(i, N) {
        ll a, b; cin >> a >> b;
        Px[i] = a; Py[i] = b;
        P[i].x = a;
        P[i].y = b;
    }
    rep(i, M) {
        ll c, d; cin >> c >> d;
        Cx[i] = c; Cy[i] = d;
        C[i].x = c;
        C[i].y = d;
    }
    vector<ll> ans;
    rep(i, N) {
        ll min = -1;
        ll num = 0;
        rep(j, M) {
            ll tmp = abs(Px[i] - Cx[j]) + abs(Py[i] - Cy[j]);
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
