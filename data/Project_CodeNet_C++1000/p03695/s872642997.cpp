#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> rate(n);
  vector<long> color(9);
  for(long i=0;i<n;i++) cin >> rate[i];
  for(long i=0;i<n;i++) color[min(8L,rate[i]/400)]++;
  for(long i=0;i<8;i++) if(color[i]>0) ans++;
  cout << max(1L,ans) << " " << ans+color[8] << endl;
}