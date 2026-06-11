#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    vector<bool>v(8,false);
    int p = 0;
    rep(i,n){
        int now = a[i];
        now /= 400;
        if(now>7){
            p++;
        }
        else{
            v[now]=true;
        }
    }
    int m = 0;
    rep(i,8){
        if(v[i])m++;
    }
    cout << max(1,m) << ' ' << m+p << endl;
    return 0;
}
