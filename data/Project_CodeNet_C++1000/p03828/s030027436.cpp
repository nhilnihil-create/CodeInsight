#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll f(ll num)
{
    if (num < 2) return 1;
    else if (num == 2) return 2;
    else if (num % 2 == 0) return 2; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return i;
        }
    }

    // 素数である
    return num;
}

vector<ll> factorList(ll x) {
  vector<ll> res;
  while (x != 1) {
    res.push_back(f(x));
    x /= f(x);
  }
  return res;
}


int main(){
  int n;
  cin >> n;
  map<int, int> M;
  if(n==1){
    cout << "1" << endl;
    return 0;
  }
  ll ans=1;
  while(n>1){
    vector<ll> fac=factorList(n);
    rep(i, fac.size()){
      M[fac[i]]++;
    }
    n--;
  }
  for(auto a: M){
    ans*=(a.second+1)%mod;
    ans%=mod;
  }
  cout << ans << endl;

  return 0;
}
