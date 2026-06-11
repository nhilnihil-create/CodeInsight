#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,ans=0,x=0; cin >> N;
  string S; cin >> S;
  for(int i=0; i<N; i++) {
    if(S[i]=='I') x++;
    else x--;
    ans = max(ans,x);
  }
  cout << ans << endl;
}