#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}
const int mod = 1e9 + 7 ; 
signed main (){
  int n;
  cin >> n;
  ll power = 1;
  for(int i = 1; i <= n;i++){
power *= i;
power %= mod;
  }

  cout << power << endl;
    return 0;

}
