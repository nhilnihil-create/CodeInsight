#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {

    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    fast();
    vector<ll> divi(1e3+8);
    vector<bool> prime(1e3+9);
    for (ll i = 2; i <= 1e3; ++i) {
        if (!prime[i]) {
            prime[i] = 1;
            for (ll j = i * i; j <= 1e3; j+=i) {
                if (!divi[j])divi[j] = i;
                prime[j]=1;
            }
        }
    }
    map<ll, ll> ans;
    ll n;
    cin >> n;
    for (ll k = n; k >= 2; --k) {
        ll tmp = k;
        while (divi[tmp]) {
            ans[divi[tmp]]++;
            tmp /= divi[tmp];
        }
        if (tmp > 1)ans[tmp]++;
    }
    ll res=1;
    ll mod=1e9+7;
    for(auto it:ans){
        res=((res%mod)*(it.second+1)%mod)%mod;
    }
    cout<<res;
}