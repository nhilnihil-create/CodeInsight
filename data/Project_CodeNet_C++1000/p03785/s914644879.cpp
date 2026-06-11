#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,c,k;
  cin >> n >> c >> k;
  vector<int>t(n);
  rep(i,0,n) cin >> t[i];
  sort(t.begin(),t.end());
  int cnt = 0,s = t[0],cn = 0;
  rep(i,0,n){
    if(t[i] > s+k || cn >= c){
      cnt++;
      cn = 0;
      s = t[i];
    }
    cn++;
  }
  if(cn != 0)cnt++;
  cout << cnt << endl;
}