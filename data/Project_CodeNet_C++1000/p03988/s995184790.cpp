#include <bits/stdc++.h>
using namespace std;

int main() {
  string ans="Impossible";
  long n;
  cin >> n;
  vector<long> a(n);
  vector<long> b(100);
  for(long i=0;i<n;i++) {
    cin >> a[i];
    b[a[i]-1]++;
  }
  for(long i=0;i<50;i++) {
    bool p=true;
    for(long j=0;j<100;j++) {
      if(i==j&&b[j]!=2) p=false;
      if((i<j&&i+i>=j)&&b[j]<2) p=false;
      if(i>j&&b[j]!=0) p=false;
      if(i+i<j&&b[j]!=0) p=false; 
    }
    if(p) ans="Possible";
  }
  for(long i=0;i<49;i++) {
    bool p=true;
    for(long j=0;j<100;j++) {
      if(i==j&&b[j]!=1) p=false;
      if((i<j&&i+i+1>=j)&&b[j]<2) p=false;
      if(i>j&&b[j]!=0) p=false;
      if(i+i+1<j&&b[j]!=0) p=false; 
    }
    if(p) ans="Possible";
  }
  
  cout << ans << endl;
}