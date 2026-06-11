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
char c[2];
  rep(i,2)
    cin >> c[i];

  rep(i,2){
    if(c[i]=='9'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No"  << endl;
  return 0;
}
