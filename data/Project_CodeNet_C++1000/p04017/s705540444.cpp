#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

const ll inf = 1LL << 60;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, L, Q;
    cin >> N;
    vector<ll> x(N+1);
    x[N] = inf;
    Rep (i, N) cin >> x[i];
    cin >> L >> Q;
    vector<ll> a(Q), b(Q);
    Rep (i, Q) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    vector<vector<ll>> dpi(20, vector<ll>(N, 0)), dpd(20, vector<ll>(N, 0));
    Rep (i, N) {
        dpi[0][i] = upper_bound(x.begin(), x.end(), x[i]+L) - x.begin() - 1;
    }


    Rep (i, 19) {
        Rep (j, N) {
            dpi[i+1][j] = dpi[i][dpi[i][j]];
        }
    }

    // Rep (i, 4) {
    //     Rep (j, N) {
    //         cout << dpi[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    Rep (i, Q) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        ll day = 0;
        for (ll j = 19; j >= 0; j--) {
            if (dpi[j][a[i]] < b[i]) {
                a[i] = dpi[j][a[i]];
                day += 1 << j;
            }
        }

        cout << day + 1 << "\n";
    }
}
