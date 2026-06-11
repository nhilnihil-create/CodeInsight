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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<double> v(N);
    rep(i, 0, N) cin >> v[i];
    sort(v.begin(), v.end(), greater<double>());
    double ave = 0;
    rep(i, 0, A) ave += v[i];
    ave /= A;
    ll sum = 0, sA = 0;
    rep(i, 0, N){
        if(v[i] == v[A-1]){
            sum++;
            if(i < A) sA++;
        }
    }
    cerr << "sum : " << sum << endl;
    cerr << "sA  : " << sA << endl;
    ll ans = 0;
    if(sA == A){
        rep(i, A, B+1){
            ans += nck(sum, sA);
            sA++;
        }
    }else{
        ans = nck(sum, sA);
    }
    printf("%.6lf\n", ave);
    cout << ans << endl;
    return 0;
}