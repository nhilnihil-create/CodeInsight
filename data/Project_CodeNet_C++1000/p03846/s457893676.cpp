#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

ll power(ll n, ll k){
  ll res = 1;
  while(k > 0){
    if (k & 1) 
      res = res * n % MOD;
    n = n * n % MOD;
    k >>= 1;
  }
  return res;
}

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<ll> hoge((n + 1)/2, 2);

  if (n % 2 == 1)
    hoge[0]--;

  int ok = 1;
  for (int i = 0; i < n; i++){
    if (a[i] % 2 == 0 && n % 2 == 0)
      ok = 0;
    if (a[i] % 2 == 1 && n % 2 == 1)
      ok = 0;

    hoge[a[i]/2]--;
  }

  for (int i = 0; i < n/2; i++){
    if (hoge[i] != 0)
      ok = 0;
  }
  if (ok){
    cout << power(2, n/2) << endl;
  }
  else
    cout << 0 << endl;


  return 0;
}
