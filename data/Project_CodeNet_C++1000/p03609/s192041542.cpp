#include <bits/stdc++.h>
#include <algorithm>
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
  ll X , t;
  cin >> X >> t;
int  ans = X -t;
  cout << max(0,ans) << endl;

    return 0;
}
