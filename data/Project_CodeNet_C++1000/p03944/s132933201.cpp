#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll W,H,N;
  cin>>W>>H>>N;
 ll up=H;
  ll down=0;
  ll left=0;
  ll right=W;
  for(ll i=0;i<N;i++) {
ll x,y,a;
    cin>>x>>y>>a;
    if(a==1) {
      left=max(left,x);
    }
    else if(a==2) {
right=min(right,x);
    }
    else if(a==3) {
      down=max(down,y);
    }
    else {
up=min(y,up);
    }
  }
  
  if(up>down&&right>left) {
cout<<(up-down)*(right-left)<<endl;
    return 0;
  }
  
  else {
cout<<0<<endl;
  }
}
  
  
  
  
  
  
  
  
  
  
  

