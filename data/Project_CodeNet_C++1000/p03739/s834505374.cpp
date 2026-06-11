#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];

  ll sum1 = 0, sum2 = 0;
  ll c1 = 0, c2 = 0;

  if(a[0] > 0){
    sum1 = a[0];
    c2 = a[0] + 1;
    sum2 = -1;
  } else if(a[0] < 0){
    sum2 = a[0];
    c1 = 1 - a[0];
    sum1 = 1;
  } else{
    sum1 = 1;
    sum2 = -1;
    c1 = c2 = 1;
  }

  rep2(i, 1, n){
    // cout << c1 << ' ' << sum1 << ' ' << c2 << ' ' << sum2 << endl;
    
    if(a[i] == 0){
      c1 += abs(sum1) + 1;
      c2 += abs(sum2) + 1;
      sum1 = sum1 > 0 ? -1 : 1;
      sum2 = sum2 > 0 ? -1 : 1;
      
      continue;
    }
    
    if((sum1 + a[i]) * (sum1 > 0 ? -1 : 1) <= 0){
      c1 += abs(((sum1 > 0 ? -1 : 1) - sum1) - a[i]);
      sum1 = sum1 > 0 ? -1 : 1;
    } else{
      sum1 += a[i];
    }
    
    if((sum2 + a[i]) * (sum2 > 0 ? -1 : 1) <= 0){
      c2 += abs(((sum2 > 0 ? -1 : 1) - sum2) - a[i]);
      sum2 = sum2 > 0 ? -1 : 1;
    } else{
      sum2 += a[i];
    }
    
  }
  
  // cout << c1 << ' ' << sum1 << ' ' << c2 << ' ' << sum2 << endl;

  cout << min(c1, c2) << endl;
  
  return 0;
}
