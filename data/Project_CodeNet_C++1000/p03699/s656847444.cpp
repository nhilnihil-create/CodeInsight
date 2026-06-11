#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> s(n);
  for(long i=0;i<n;i++) cin >> s[i];
  
  sort(s.begin(),s.end());
  for(long i=0;i<n;i++) {
    ans+=s[i];
  }
  if(ans%10==0) {
    for(long i=0;i<n;i++) {
      if(s[i]%10!=0) {
        ans-=s[i];
        break;
      }
      if(i+1==n) ans=0;
    }
  }
  cout << ans << endl;
}