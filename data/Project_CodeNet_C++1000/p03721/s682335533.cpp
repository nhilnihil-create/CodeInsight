#include <bits/stdc++.h>
using namespace std;
#define ll long long  
template <typename T>
bool PN(T x)
{
  if (x <= 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i < sqrt(x) + 1; i++)
    if (x % i == 0)
      return false;
  return true;
}

const long long MOD = 1e9+7;

void solve()
{
  ll n, k;
  scanf("%lld %lld", &n, &k);
  map<int,ll> mp;
  for(int i = 0; i < n; ++i){
    int a, b;
    cin >> a >> b;
    mp[a] += b;
  }
  ll cnt = 0;
  for(auto mm: mp){
    cnt += mm.second;
    if(k <= cnt) {
      cout << mm.first << endl;
      return;
    }
  }  
}

int main()
{
  solve();
  return 0;
}