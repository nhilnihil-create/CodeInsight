#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, n;
  cin >> w >> h >> n;
  int r=w, l=0, u=h, d=0;
  int x[n], y[n], a[n];
  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i] >> a[i];
    if(a[i]==1 && x[i]>l)
      l=x[i];
    else if(a[i]==2 && x[i]<r)
      r=x[i];
    else if(a[i]==3 && y[i]>d)
      d=y[i];
    else if(a[i]==4 && y[i]<u)
      u=y[i];
    }
  if(u-d>0&&r-l>0)
    cout << (u-d)*(r-l);
  else
    cout << 0;
  return 0;
}