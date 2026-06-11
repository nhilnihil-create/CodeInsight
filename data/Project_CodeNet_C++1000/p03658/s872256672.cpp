#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(n); i++)//第一引数の変数をカウンタ変数としてn回回す
//repはカウンタ変数が1ずつ増える場合にしか使えない
using veci = vector<int>;
using vecd = vector<double>;
int sq(int a){
  return a*a;
}
int main(){//受け取った配列を昇順にソートして、ｋだけ貪欲にとる
  int n, k;
  cin >> n >> k;
  int a[60];
  rep(i, n){
    cin >> a[i];
  }
  sort(a, a+n, [](int a, int b){ return a>b;});
  int ans=0;
  rep(i, k){
    ans += a[i];
  }
  cout << ans << endl;
}
    