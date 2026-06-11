#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ansa=0,ansb=0,x=0,y=0;
  cin >> n;
  vector<long> a(n),wa(n);
  for(long i=0;i<n;i++) cin >> a[i];
  wa[0]=a[0];
  for(long i=1;i<n;i++) wa[i]=wa[i-1]+a[i];
  for(long i=0;i<n;i++) {
    if(i%2==0) {
      if(wa[i]+x<=0) {
        ansa+=1-wa[i]-x;
        x+=1-wa[i]-x;
      }
      if(wa[i]+y>=0) {
        ansb+=1+wa[i]+y;
        y+=-1-wa[i]-y;
      }
    } else {
      if(wa[i]+x>=0) {
        ansa+=1+wa[i]+x;
        x+=-1-wa[i]-x;
      }
      if(wa[i]+y<=0) {
        ansb+=1-wa[i]-y;
        y+=1-wa[i]-y;
      }
    }
  }
  cout << min(ansa,ansb) << endl;
}