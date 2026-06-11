#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n, p;
    cin >> n >> p;
    int n0, n1;
    n0 = n1 = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if(a % 2 == 0) n0++;
        else n1++;
    }
    ll ans = 0;
    if(p % 2 == 0) {
        if(n1 == 0) ans = pow(2, n0);
        else ans = pow(2, n0 + n1 -1);
    } else {
        if(n1 == 0) ans = 0;
        else ans = pow(2, n0 + n1 - 1);
    }
    cout << ans << endl;

    return 0;
}