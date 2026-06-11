#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

#define rep(i, n) for(ll i=0; i<n; ++i)

//--------------------

ll N;
ll A[100001];
map<ll, ll> M;
vector<pair<ll, ll>> V;

int main() {

  cin >> N;
  rep(i, N) {
    cin >> A[i];
    ++M[A[i]];
  }

  ll res = 0;

  for(auto it : M) {
    if(it.second>=2) {
      V.push_back({it.first, it.second});
    }
  }

  ll size = V.size();
  if(size>0) {
    sort(V.begin(), V.end());
    if(V[size-1].second>=4)
      res = V[size-1].first*V[size-1].first;
    else
      res = V[size-1].first*V[size-2].first;
  }

  cout << res << endl;

  return 0;
}
