#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(){
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A.at(i);

  B.at(0) = 0;
  for (int i = 1; i < N; i++){
    B.at(i) = A.at(i) - A.at(i-1);
  }

  bool flag1 = true, flag2 = true;

  int ans = 0;

  rep(i,N){
    if(B.at(i) > 0) flag2 = false;
    else if (B.at(i) < 0) flag1 = false;

    if (!flag1 && !flag2){
      ans++;
      flag1 = true;
      flag2 = true;
    } 
  }

  ans++;

  cout << ans << endl;
}