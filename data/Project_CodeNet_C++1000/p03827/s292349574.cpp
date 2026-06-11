#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  string S;
  cin >> N >> S;

  int x = 0;
  int mx = 0;
  rep(i,N){
    if (S[i] == 'I'){
      x += 1;
    }else{
      x -= 1;
    }
    mx = max(mx, x);
  }
  cout << mx << endl;
}
