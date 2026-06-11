#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> a(n),kyusyu(n),kanou(n,1);
  for(long i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  long j=0;
  for(long i=0;i<n;i++) {
    if(i!=0) kyusyu[i]=kyusyu[i-1];
    for(;j<n;j++) {
      if(a[j]>a[i]*2) break;
      kyusyu[i]+=a[j];
    }
  }
  j=0;
  for(long i=0;i<n-1;i++) {
    while(j+1!=n) {
      if(a[j+1]>kyusyu[i]*2) break;
      j++;
    }
    kanou[j]+=kanou[i];
  }
  ans=kanou.back();
  
  cout << ans << endl;
}