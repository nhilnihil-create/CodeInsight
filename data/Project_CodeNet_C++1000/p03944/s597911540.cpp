#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int w,h,n;
  cin >> w >> h >> n;
  
  int x[n],y[n],a[n];
  rep(i,n) cin >> x[i] >> y[i] >> a[i];
  
  int withl = 0,withr = w;
  int haiu = 0,haio = h;; 
  rep(i,n){
    if(a[i] == 1){
      if(x[i] > withl){
        withl = x[i];
      }
    }else if(a[i] == 2){
      if(x[i] < withr){
        withr = x[i];
      }
    }else if(a[i] == 3){
      if(y[i] > haiu){
        haiu = y[i];
      }
    }else if(a[i] == 4){
      if(y[i] < haio){
        haio = y[i];
      }
    }//else if
  }
  
  if(withl >= withr || haiu >= haio){
    cout << 0 << endl;
    return 0;
  }
    
  cout << (withr - withl) * (haio - haiu) << endl;
}