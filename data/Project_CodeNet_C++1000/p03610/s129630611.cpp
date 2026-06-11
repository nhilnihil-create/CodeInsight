#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(n); i++)//第一引数の変数をカウンタ変数としてn回回す
//repはカウンタ変数が1ずつ増える場合にしか使えない
using veci = vector<int>;
using vecd = vector<double>;
int main(){
  string s;
  cin >> s;
  string ans = "";
  for (int i=0; i<s.size(); i+=2){
    ans += s.at(i);
  }
  cout << ans << endl;
}