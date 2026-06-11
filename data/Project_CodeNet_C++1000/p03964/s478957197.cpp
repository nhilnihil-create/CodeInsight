#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i, N, T, A; cin >> N; long m, c, d, a=1, t=1, ans=2;
for(i=0; i<N; i++){
  cin >> T >> A; c=a/A; d=t/T; m=max(c, d);
  if((c>=d && a%A) || (d>=c && t%T)){ m++; }
  a=m*A; t=m*T; ans=a+t;
}
cout << ans << "\n";
}