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
  int N;
  int used = 0; 
  cin >> N;
  rep(i,N){
    int l , r;
    cin >> l >> r;
      used += (r - l +1); 
  }
  cout << used << endl;
  return 0;
}
