#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<long long, long long>> v;
  for(int i = 0; i < n; i++){
    long long a, b;
    cin >> a >> b;
    v.emplace_back(a, b);
  }
  sort(v.begin(), v.end());
  long long ans = v[0].first;
  for(int i = 0; i < n-1; i++){
    ans += min(abs(v[i].first - v[i+1].first), abs(v[i].second - v[i+1].second));
  }
  ans += v[n-1].second;
  cout << ans << endl;
  return 0;
}