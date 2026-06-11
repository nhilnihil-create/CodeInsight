#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  long H,W;
  cin >> H>>W;
  long sa=1001001001;
  rep(i,H){
    long a=i*W;
    long b;
    long c;
    if((H-i)%2==0){
      b=(H-i)/2*W;
      c=H*W-a-b;
    }
    else{
      if(W%2==0){
        b=W/2*(H-i);
        c=H*W-a-b;
      }
      else{
        b=max(W,H-i)/2*min(W,H-i);
        c=H*W-a-b;
      }
    }
    sa=min(sa,abs(max(a,c)-min(a,b)));
  }
  rep(i,W){
    long a=i*H;
    long b;
    long c;
    if((W-i)%2==0){
      b=(W-i)/2*H;
      c=H*W-a-b;
    }
    else{
      if(H%2==0){
        b=H/2*(W-i);
        c=H*W-a-b;
      }
      else{
        b=max(H,W-i)/2*min(H,W-i);
        c=H*W-a-b;
      }
    }
    sa=min(sa,abs(max(a,c)-min(a,b)));
  }
 
    cout<<sa<<endl;
  
}




