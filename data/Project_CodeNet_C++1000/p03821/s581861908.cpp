#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int N; cin >> N;
  vector<ll> a(N), b(N);
  rep(i, N) cin >> a[i] >> b[i];

  ll n_plus = 0;
  for (int i = N - 1; i >= 0; --i){
    a[i] += n_plus;
    if (a[i] % b[i] == 0) continue;
    if (a[i] > b[i]){
      ll k = a[i] / b[i] + 1;
      n_plus += b[i] * k - a[i];
    }
    else{
      n_plus += b[i] - a[i];
    }
  }
  cout << n_plus << endl;
}
