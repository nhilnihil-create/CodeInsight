#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    int n, x;
    cin >> n >> x;
    V<int> a(n);
    rep(i,n) cin >> a[i];
    int idx = -1;
    Rep(i,n-1) {
        if(a[i] + a[i-1] >= x) idx = i;
    }
    if(idx == -1) 
        cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        for(int i = 1; i < idx; i++) cout << i << endl;
        for(int i = n-1; i > idx; i--) cout << i << endl;
        cout << idx << endl;
    }
}