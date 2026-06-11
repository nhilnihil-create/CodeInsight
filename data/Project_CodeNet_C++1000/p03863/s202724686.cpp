#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  string s; cin >> s;
  bool cond1 = (s.size()%2 == 0);
  bool cond2 = (s[0] == s[s.size()-1]);
  if(cond1^cond2) cout << "Second" << endl;
  else cout << "First" << endl;
  
  return 0;
}