#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll at_amari = 1000000007; //10^9 + 7 

ll kaizyo(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    sum = sum % at_amari;
  }

  return sum;
}

int main(){
  int n,m; cin >> n >> m;
  ll n_zyun = kaizyo(n),m_zyun = kaizyo(m),ans = 0;
  //cout << n_zyun << ' ' << m_zyun << endl;
  
  if(abs(n - m) > 1) {
    ans = 0;
    //cout << 1 << endl;
  }
  else if(n < m || n > m) {
    ans = n_zyun * m_zyun;
    //cout << 12 << endl;
  }
  else if(n == m) {
    ans = n_zyun * m_zyun * 2;
    //cout << 1123 << endl;
  }

  ans = ans % at_amari;
  

  cout << ans << endl;
  
}

