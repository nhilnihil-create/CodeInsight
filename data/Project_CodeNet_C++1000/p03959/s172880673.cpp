#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=0,mod=1000000007;
  bool b=true;
  cin >> n;
  vector<long> t(n),a(n),max(n);
  vector<bool> ika(n,true);
  for(long i=0;i<n;i++) cin >> t[i];
  for(long i=0;i<n;i++) cin >> a[i];
  
  max[0]=t[0];
  ika[0]=false;
  for(long i=1;i<n;i++) {
    max[i]=t[i];
    if(t[i-1]!=t[i]) ika[i]=false;
  }
  
  if(ika[n-1]) {
    if(max[n-1]<a[n-1]) b=false;
    else {
      max[n-1]=a[n-1];
      ika[n-1]=false;
    }
  } else {
    if(max[n-1]!=a[n-1]) b=false;
  }
  for(long i=n-2;i>=0;i--) {
    if(a[i]!=a[i+1]) {
      if(ika[i]) {
        if(max[i]<a[i]) b=false;
        else {
          max[i]=a[i];
          ika[i]=false;
        }
      } else {
        if(max[i]!=a[i]) b=false;
      }
    } else {
      if(ika[i]) max[i]=min(max[i],a[i]);
      else if(a[i]<max[i]) b=false;
    }
  }
  
  if(b) {
    ans=1;
    for(long i=0;i<n;i++) {
      if(ika[i]) ans=ans*max[i]%mod;
    }
  }
  cout << ans << endl;
}