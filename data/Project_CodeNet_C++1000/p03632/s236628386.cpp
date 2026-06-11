#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll time[301];
    ll ans = 0;

    fill(time,time+301,0LL);

    for(ll i = a; i < b; i++){
        time[i]++;
    }
    for(ll i = c; i < d; i++){
        time[i]++;
    }

    for(long long i = 0; i < 301; i++){
        if(time[i] == 2) ans++;
    }

    put(ans);
}