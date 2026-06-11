#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  vector<int> v(8);
  rep(i, 8) v[i] = 0;
  int m;
  int cnt = 0;
  int mi = 101, ma = -1;
  rep(i, n){
    cin >> m;
    if(m >= 3200) cnt++;
    else if(m >= 2800) {
      mi = min(mi, ++v[7]);
      ma = max(ma, ++v[7]);
    }
    else if(m >= 2400) {
      mi = min(mi, ++v[6]);
      ma = max(ma, ++v[6]);
    }
    else if(m >= 2000) {
      mi = min(mi, ++v[5]);
      ma = max(ma, ++v[5]);
    }
    else if(m >= 1600) {
      mi = min(mi, ++v[4]);
      ma = max(ma, ++v[4]);
    }
    else if(m >= 1200) {
      mi = min(mi, ++v[3]);
      ma = max(ma, ++v[3]);
    }
    else if(m >= 800) {
      mi = min(mi, ++v[2]);
      ma = max(ma, ++v[2]);
    }
    else if(m >= 400) {
      mi = min(mi, ++v[1]);
      ma = max(ma, ++v[1]);
    }
    else{
      mi = min(mi, ++v[0]);
      ma = max(ma, ++v[0]);
    }
  }
  int ans = 0;
  rep(i, 8){
    if(v[i]) ans++;
  }
  cout << (ans > 0 ? ans : 1) << " ";
  ans += cnt;
  cout << ans << endl;
  return 0;
}
