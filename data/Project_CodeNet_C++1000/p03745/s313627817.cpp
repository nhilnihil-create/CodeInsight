#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v[0];
  int ans = 0;
  int dir = 0;
  rep(i, n){
    cin >> v[i];
    if (dir == 0){
      if (v[i-1] < v[i]){
        dir = 1;
      } else if (v[i-1] > v[i]){
        dir = -1;
      }
    }

    if ((dir == 1) && (v[i-1] > v[i])){
      dir = 0;
      ++ans;
    } else if ((dir == -1) && (v[i-1] < v[i])){
      dir = 0;
      ++ans;
    }
  }
  cout << ans + 1 << endl;

  return 0;
}