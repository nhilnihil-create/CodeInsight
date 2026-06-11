#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

const int mod = 1e9+7;

ll nodOfFact(int n){
  vector<int> isp(n+1, 1);
  for (int i = 2; i*i <= n; ++i){
    if(isp[i]){
      for (int j = i*i; j <= n; j+=i){
        isp[j]=0;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= n; ++i){
    if(isp[i]){
      primes.push_back(i);
    }
  }

  ll ret = 1;
  for(auto& u: primes){
    ll p = u;
    int e = 0;
    while(p<=n){
      e += n/p;
      p *= u;
    }
    ret *= (e+1);
    ret %= mod;
  }
  return ret;

}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int n;  cin >> n;
  cout << nodOfFact(n) << "\n";
  return 0;
}