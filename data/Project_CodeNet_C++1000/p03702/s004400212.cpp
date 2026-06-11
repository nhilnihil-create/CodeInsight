#include <bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)


int main(){
 long n,a,b;
   cin >> n >> a >> b;
  vector<long> h(n);
  long hmax=0;
  rep(i,0,n) {
    cin >> h[i];
    hmax=max(hmax,h[i]);
  }
  
  long l=0;
  long r=(hmax-1)/b+1;
  long d=a-b;
  while(l<r){
   long t=(l+r)/2;
    long num=0;
    
    rep(i,0,n){
      long v=h[i]-b*t;
    if(v>0) num+=(v-1)/d+1;
    }
    if(num<=t) r=t;
    else l=t+1;
  
  }
  
   cout << r << endl;
}