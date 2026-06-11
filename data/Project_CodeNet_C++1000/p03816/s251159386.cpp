#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  map<ll, ll> m;
  ll t = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    if (m[a[i]] != 0)
      t++;
    m[a[i]]++;
  }


  cout << n - 2*((t + 1)/ 2) << endl;
  

  return 0;
}
