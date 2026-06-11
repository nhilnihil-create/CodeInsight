#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

char ans[110];

int main(){
    string o, e;
    cin >> o >> e;

    rep(i, o.size()){
        ans[2*i] = o[i];
    }
    rep(i, e.size()){
        ans[2*i+1] = e[i];
    }
    rep(i, o.size()+e.size()){
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
