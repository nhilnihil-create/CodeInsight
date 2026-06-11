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
    
    int n, m;
    cin >> n >> m;
    V<int> a(n), b(n), c(m), d(m);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,m) cin >> c[i] >> d[i];

    rep(i,n) {
        int ans = -1;
        int dist = inf;
        rep(j,m) {
            int tmp = abs(c[j] - a[i]) + abs(d[j] - b[i]);
            if(dist > tmp) {
                dist = tmp;
                ans = j+1;
            }
        }
        cout << ans << endl;
    }
}