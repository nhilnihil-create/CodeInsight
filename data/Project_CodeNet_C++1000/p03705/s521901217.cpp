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
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans;
    if(a > b) ans = 0;
    else if(n == 1) {
        if(a == b) ans = 1;
        else ans = 0;
    } else {
        ans = (a + b * (n - 1)) - (b + a * (n - 1)) + 1;
    }
    cout << ans << endl;

    return 0;
}