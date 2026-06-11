#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

#define MOD 1000000007
int main(){
    ll n;
    cin >> n;
    vector<ll> t(n), a(n);
    rep(i, n)cin >> t[i];
    rep(i, n)cin >> a[i];
    bool tmax[100010] = {false};
    bool amax[100010] = {false};
    tmax[0] = amax[n-1] = true;
    for(ll i = 1; i < n; ++i)if(t[i]!=t[i-1])tmax[i]=true;
    for(ll i = n-2; i >= 0; --i)if(a[i]!=a[i+1])amax[i]=true;
    ll ans = 1;
    rep(i, n){
        if(tmax[i] && t[i] > a[i])ans = 0;
        if(amax[i] && a[i] > t[i])ans = 0;
        if(!(tmax[i]|amax[i]))ans=(ans*min(t[i],a[i]))%MOD;
    }

    cout << ans << endl;
}