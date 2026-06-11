#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
  int K,S;
  cin >> K >> S;
  int x,y,z;
  int sum;
  int cnt = 0;
  rep(i,K+1){
    rep(j,K+1){
      sum = i + j;
      if(S - sum <= K && 0 <= S - sum ) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
