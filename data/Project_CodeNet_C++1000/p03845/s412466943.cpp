#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<ll,pair<ll,ll>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> t(n);
    rep(i, n)cin >> t[i];
    int sum = accumulate(all(t), 0);
    cin >> m;
    rep(i, m){
        int p, x;
        cin >> p >> x; p--;
        cout << sum - t[p] + x << endl;
    }
}