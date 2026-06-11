#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <set>
#include <string.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REP3(i,st,en) for(ll (i)=(st);(i)<(en);(i)++)

using P = pair<ll, ll>;
const int MOD = 1e9+7;
const ll INF = 1e+14;
const double PI = 3.14159265349;

ll euclid(ll a, ll b){
  while (b>1){
    a = a % b;
    swap(a,b);
  }
  return a;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  vector<ll> T(N);
  vector<ll> A(N);
  REP(i, N){ cin >> T[i] >> A[i]; }

  ll x=1;
  ll y=1;
  REP(i, N){
    x = (x%T[i]==0) ? x/T[i] : x/T[i]+1;
    y = (y%A[i]==0) ? y/A[i] : y/A[i]+1;
    ll p = max(x,y);
    x = T[i]*p;
    y = A[i]*p;
  }

  cout << x+y << "\n";
  return 0;
}
