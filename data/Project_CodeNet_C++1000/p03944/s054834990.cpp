#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int w, h, n;
  cin >> w >> h >> n;
  int x = 0, y = 0;
  int a[n], b[n], c[n];
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
  rep(i, n){
    if(c[i] == 1){
      if(x <= a[i]) x = a[i];
    }
    else if(c[i] == 3){
      if(y <= b[i]) y = b[i];
    }
    else if(c[i] == 2){
      if(w >= a[i]) w = a[i];
    }
    else{
      if(h >= b[i]) h = b[i];
    }
  }
  int ws = (w - x >= 0 ? w - x : 0);
  int hs = (h - y >= 0 ? h - y : 0);
  cout << ws * hs << endl;
      
  
  

  return 0;
}