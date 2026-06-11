#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
  int N,K;
  cin >> N >> K;
  vint l(N);
  rep(i,N){
cin >> l.at(i);
  }
sort(all(l),greater<int>());
int ans = 0;
rep(i,K){
ans += l.at(i);
}
cout << ans << endl;
    return 0;
}
