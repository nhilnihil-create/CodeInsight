#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int n;
  cin >> n;
  int ans;
  int s = -1;
  for(int i = 1; i <= n; i++){
    int t = i;
    int cnt = 0;
    while(true){
      if(t%2 != 0) break;
      t /= 2;
      cnt++;
    }
    if(cnt > s){
      s = cnt;
      ans = i;
    }
  }
  cout << ans << endl;
 }
