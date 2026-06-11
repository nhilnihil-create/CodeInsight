#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define sz size()
#define pb push_back
#define bg begin()
#define ed end()
#define fi first()
#define se second()
using namespace std;
using ll = long long;
using vint = vector<int>;
using pint = pair<int,int>;
using vpint = vector<pint>;
template <typename T>
T sq(T x){
  return x * x;
}
ll mod = 1e9 + 7;

signed main (){
  string s;
  cin >> s;
  map<char,int> m;
  rep(i,s.sz){
    ++m[s.at(i)];
  }
  rep(i,26){

    if(m['a' + i] == 0){
      cout << char('a'+ i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;    
  return 0;
}
