#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// a^n mod を計算する(拡張ユークリッドの互除法)
//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
  int n;//10**5
  cin >> n;
  vector<int> a(n);//差の列
  vector<int> b(n);
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    b.at(a.at(i))++;
  }
  int flag = 0;
  for(int i = 1; i < n; i++){
    if(b.at(i)!=0&&b.at(i)!=2){
      flag = 1;
      break;
    }
  }
  if(flag)cout << 0 << endl;
  else cout << modpow(2,n/2,MOD) << endl;
  return 0;
}
