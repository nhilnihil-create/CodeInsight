#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


int main(){
    int n;
    cin >> n;
    ll a[n], b[n];
    rep(i, n) cin >> a[i] >> b[i];
    ll tmp = 0;
    rrep(i, n){
        a[i] += tmp;
        ll res;
        if (a[i] % b[i] != 0) res = b[i] - a[i] % b[i];
        else res = 0;
        tmp += res;
    }
    cout << tmp << endl;
    return 0;
}