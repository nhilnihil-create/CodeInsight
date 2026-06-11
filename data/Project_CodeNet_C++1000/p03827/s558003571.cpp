#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll int64_t
#define all(v) v.begin(), v.end()
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)
#define bitrep2(n) for(int bit2=0;bit2<(1<<n);bit2++)


int main() {

int A,B,C,D,N; cin >> N;
string S; cin >> S;

int ans=0,temp=0;

rep(i,N){
  if(S[i]=='I') temp++;
  else temp--;

  ans=max(ans,temp);
}

cout << ans << endl;

return 0;
}