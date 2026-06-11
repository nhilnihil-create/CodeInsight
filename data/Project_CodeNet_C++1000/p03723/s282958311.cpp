#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    vector<ll>v(3);
    rep(i, 0, 3)cin >> v[i];
    sort(v.begin(),v.end());
    ll a, b, c;
    a = v[0], b = v[1], c = v[2];
    if(a%2==1||b%2==1||c%2==1){
        cout << 0 << endl;
        return 0;
    }
    if(a==b&&b==c){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    while(a%2==0&&b%2==0&&c%2==0){
        ll tempa = (b+c)/2;
        ll tempb = (a+c)/2;
        ll tempc = (a+b)/2;
        a = tempa;
        b = tempb;
        c = tempc;
        ans++;
    }
    cout << ans << endl;
}