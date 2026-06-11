#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

ll com(int n,int k){
    ll res = 1;
    for(int i=0;i<k;i++){
        res *= n-i;
        res /= i+1;
    }
    return res;
}

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(v.rbegin(),v.rend());
    ll res = 0;
    rep(i,a) res += v[i];
    cout << setprecision(20) << (res/(double)a) << endl;
    ll c=0,cc=0;
    rep(i,n){
        cc += (v[a-1]==v[i]);
        if(i<a) c += (v[a-1]==v[i]);
    }
    ll now = com(cc,c);
    if(v[0]!=v[a-1]){
        cout << now << endl;
        return 0;
    }
    ll ans = 0;
    for(int i=a;i<=min(cc,(ll)b);i++){
        ans += com(cc,i);
    }
    cout << ans << endl;
    return 0;
}