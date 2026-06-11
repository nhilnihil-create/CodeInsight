#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
  
int main(){
  int N; cin >> N;
  int ans =0;
  rep(i,N) ans += i+1;
  
  cout << ans << endl;
}