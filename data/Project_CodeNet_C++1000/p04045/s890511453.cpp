#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,k,ans;
  cin >> n >> k;
  vector<long> d(k);
  vector<bool> b(10);
  
  for(long i=0;i<k;i++) cin >> d[i];
  for(long i=0;i<k;i++) b[d[i]]=true;
  for(ans=n;true;ans++) {
    bool a=true;
    for(long i=1;i<=ans;i*=10) if(b[ans/i%10]) a=false;
    if(a) break;
  }
  cout << ans << endl;
}