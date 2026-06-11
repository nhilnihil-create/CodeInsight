#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,b,c,d;cin >> n >> a >> b >> c >> d;
    b-=a;
    vector<ll> l(n+1),r(n+1);
    l[0]=-(n-1)*d,r[0]=-(n-1)*c;
    REP(i,n){
        l[i+1]=l[i]+c+d;
        r[i+1]=r[i]+c+d;
    }
    REP(i,n+1){
        if(l[i]<=b&&b<=r[i]){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}