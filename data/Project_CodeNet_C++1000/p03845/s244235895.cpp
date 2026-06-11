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
  
  ll sum = 0;
  vector<ll> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
    sum += t[i];
  }
  ll m;
  cin >> m;
  
  for (int i = 0; i < m; i++){
    ll p, x;
    
    cin >> p >> x;
    p--;
    cout << sum + x - t[p] << endl;
  }
  
  

  return 0;
}
