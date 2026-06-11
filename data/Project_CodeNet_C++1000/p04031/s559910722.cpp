#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];

    ll ans = 1e9;

    for(int i = -100; i < 101; i++){
        ll sum = 0;
        for(int j = 0; j < n; j++){
            sum += pow((a[j] - i),2);
        }
        ans = min(ans, sum);
    }

    put(ans);
}