#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;



int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  int ans=0, pre=a[0], tmp=1;
  for(int i=1; i<n; i++){
    if(a[i]==pre) tmp++;
    else{
      if(tmp%2==1) ans++;
      tmp = 1;
    }
    pre=a[i];
  }
  if(tmp%2==1)ans++;
  cout << ans << endl;

  return 0;
}
