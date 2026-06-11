#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<P>data(n);
  rep(i,0,n) cin >> data[i].second >> data[i].first;
  sort(data.begin(),data.end());
  int ans = data[0].first+data[0].second;
  cout << ans << endl;
}