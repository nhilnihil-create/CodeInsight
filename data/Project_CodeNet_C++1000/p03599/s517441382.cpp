#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long a,b,c,d,e,f,ansa,ansb;
  long double ans=-1;
  cin >> a >> b >> c >> d >> e >> f;
  vector<bool> water(f/100+1);
  vector<bool> sugar(1501);
  water[0]=true;
  sugar[0]=true;
  for(long i=1;i<f/100+1;i++) {
    if(i>=a) if(water[i-a]) water[i]=true;
    if(i>=b) if(water[i-b]) water[i]=true;
  }
  for(long i=1;i<1501;i++) {
    if(i>=c) if(sugar[i-c]) sugar[i]=true;
    if(i>=d) if(sugar[i-d]) sugar[i]=true;
  }
  for(long i=1;i<f/100+1;i++) {
    for(long j=0;j<1501;j++) {
      if(i*100+j>f) break;
      if((j+i-1)/i>e) break;
      if(water[i]&&sugar[j]) {
        if(j*1.0/i>ans) {
          ans=j*1.0/i;
          ansa=i*100+j;
          ansb=j;
        }
      }
    }
  }
  cout << ansa << " " << ansb << endl;
}