#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n ; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll ans = 0;
    bool flag = false;

    rep(i,n){
        ll x = a.at(i);
        ans += x/2;
        bool flag2 = false;
        if(x==1 && flag) flag2 = true;

        if(i<(n-1) && x%2 && !flag2){
            a.at(i+1)++;
            flag = true;
        }else{
            flag = false;
        }        
    }

    cout << ans << endl;
}