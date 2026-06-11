#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N, M;
  cin >> N >> M;
  long long ans;
  if(N>M/2) ans = M/2;
  else ans = max(N, N+(M-2*N)/4);
  cout << ans << endl;
}