#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

ll solve(int h, int w) {
    ll mn;
    if (h % 3 == 0) return 0;
    else mn = w;
    if (w % 2 == 0) {
        for (ll x = 1; x <= h-1; x++) {
            mn = min(mn,abs(w*x-(h-x)*(w/2)));
        }
    }
    else {
        for (ll x = 1; x <= h-1; x++) {
            ll s1 = w*x;
            ll s2 = (w/2)*(h-x);
            ll s3 = ((w+1)/2)*(h-x);
            mn = min(mn,max({s1,s2,s3})-min({s1,s2,s3}));
        }
    }
    return mn;
}

int main() {
    int h, w; cin >> h >> w;
    ll mn = inf_l;
    mn = min(mn,solve(h,w));
    swap(h,w);
    mn = min(mn,solve(h,w));
    cout << mn << endl;
}