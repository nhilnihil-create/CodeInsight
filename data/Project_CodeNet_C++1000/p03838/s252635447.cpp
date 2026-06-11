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
    ll x, y;
    cin >> x >> y;
    vector<int> a = {1, 1, -1, -1};
    vector<int> b = {1, -1, 1, -1};

    ll minv = LINF;
    rep(i, 4) {
        ll cnt = 0;
        ll c = x, d = y;
        if(a[i] == -1) {
            cnt++;
            c *= -1;
        }
        if(b[i] == -1) {
            cnt++;
            d *= -1;
        }
        if(d >= c) cnt += d - c;
        else continue;
        
        minv = min(minv, cnt);
    }
    cout << minv << endl;

    return 0;
}