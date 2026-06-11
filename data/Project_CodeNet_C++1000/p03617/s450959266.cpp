#include <bits/stdc++.h>
using namespace std;
 
int main() {unsigned long long int Q,H,S,D,N;
  cin >> Q >> H >> S >> D >>N;
 unsigned long long int ans;
  if(8*Q<=4*H && 8*Q<=2*S && 8*Q <=D)
  {ans=4*Q*N;}
  else if (4*H<=2*S && 4*H<=D)
  {ans=2*H*N;}
  else if (2*S<=D)
  {ans=S*N;}
  
  else{
    if(N%2==0)
    {ans=N*D/2;}
    else {
      if(8*Q<=4*H && 8*Q<=2*S)
      {ans = (N-1)/2*D + 4*Q;}
      else if(4*H<=2*S)
      {ans = (N-1)/2*D + 2*H;}
      else
      {ans = (N-1)/2*D + S;}
    }
  }
    cout << ans << endl;
}