#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=0;
  cin >> n;
  vector<long> a(n);
  map<long,long> mp;
  for(long i=0;i<n;i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for(auto itr=mp.begin();itr!=mp.end();itr++) {
    if((*itr).second%2!=0) ans++;
  }
  cout << ans << endl;
}