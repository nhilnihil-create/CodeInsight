#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll nck(ll n, ll k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  if(k == 0 || k == n) return 1;
  ll nume = 1, deno = 1;
  for(int i=0; i<k; i++){
    nume *= (n-i);
    deno *= (i+1);
    ll g = gcd(nume, deno);
    nume /= g;
    deno /= g;
  }
  return (ll)(nume/deno);
}


int main(){
    ll n, p;
    cin >> n >> p;
    ll odd = 0, even = 0;
    rep(i, 0, n){
        ll a;
        cin >> a;
        if(a % 2 == 0) even++;
        else odd++;
    }
    
    if(p == 0){
        ll d = 0;
        ll srt;
        if(odd % 2 == 1) srt = 1;
        else srt = 0;
        for(ll i = srt; i <= odd; i += 2){
            d += nck(odd, i);
        }
        ll ans = pow(2LL, even) * d;
        cout << ans << endl;
    }else{
        ll d = 0;
        ll srt;
        if(odd % 2 == 1) srt = 0;
        else srt = 1;
        for(ll i = srt; i <= odd; i += 2){
            d += nck(odd, i);
        }
        ll ans = pow(2LL, even) * d; 
        cout << ans << endl;
    }
    return 0;
}