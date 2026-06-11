#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

bool compare(const pair<ll, ll>& lh, const pair<ll, ll>& rh) {
  if (lh.first < rh.first){
    return true;
  } else if (lh.first == rh.first){
    if (lh.second >= rh.second)
      return true;
  }
  
  return false;
}

int main(void){
  ll n;
  cin >> n;
  
  vector<pair<ll, ll>> a(n);
  ll num = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i].first;
    a[i].second = i;
    num += a[i].first;
  }
  sort(a.begin(), a.end());

  vector<ll> res(n, 0);
  ll id = n - 1, mi = n;
  while (true){
    while (id > 0 && a[id].first == a[id-1].first){
      id--;
    }
    if (id == 0){
      res[0] += n*a[0].first;
      break;
    }
    mi = min(mi, a[id].second);
    res[mi] += (n - id)*(a[id].first - a[id-1].first);
    id--;
  }


  for (int i = 0; i < n; i++){
    cout << res[i] << endl;
  }
  

  return 0;
}
