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

int main(){
    int n;
    cin >> n;
    vector<int> t(n),a(n);
    rep(i,n) cin >> t[i];
    rep(i,n) cin >> a[i];
    vector<int> dec(n,-1),under(n,INF);
    dec[0] = t[0];
    int now = t[0];
    for(int i=1;i<n;i++){
        if(now < t[i]){
            dec[i] = t[i];
            now = t[i];
        }else{
            under[i] = now;
        }
    }

    if(dec[n-1]==-1){
        if(under[n-1]<a[n-1]){
            cout << 0 << endl;
            return 0;
        }
    }else{
        if(dec[n-1]!=a[n-1]){
            cout << 0 << endl;
            return 0;
        }
    }

    dec[n-1]=a[n-1];
    now = a[n-1];
    for(int i=n-2;i>=0;i--){
        if(now < a[i]){
            if(dec[i]!=-1&&dec[i]!=a[i]){ cout << 0 << endl;return 0;}
            if(dec[i]==-1&&under[i]<a[i]){ cout << 0 << endl;return 0;}
            dec[i] = a[i];
            now = a[i];
        }else{
            if(dec[i]!=-1&&dec[i]>now){ cout << 0 << endl;return 0;}
            under[i] = min(now,under[i]);
        }
    }
    ll ans = 1;
    rep(i,n){
        if(dec[i]==-1){
            ans = (ans * (ll)under[i]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}