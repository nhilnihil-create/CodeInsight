#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int k, s;
  cin >> k>> s;

  int count = 0;
  rep(i, k){
    rep(j, k){
      int l = s - (i + j);
      if (l >= 0 && l <= k){
        ++count;
      }
    }
  }
  cout << count << endl;
  return 0;
}