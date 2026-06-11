#include<bits/stdc++.h>
using namespace std;
int main(void) {
  int n,l[1000],r[1000],a[1000],ans=0;
  cin >> n;
  for(int i=0;i<n;++i) cin >> l[i] >> r[i];
  for(int i=0;i<n;++i) {
    a[i] = r[i] - l[i] + 1;
    ans = ans + a[i];
  }
  cout << ans << endl;
}