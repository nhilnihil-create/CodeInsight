#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll int64_t
#define all(v) v.begin(), v.end()
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)

//貪欲法はクソ
int main() {

  int x,a,b; cin >> x >> a >> b;

  int da=abs(a-x),db=abs(b-x);

  if(da<db) cout << 'A' << endl;

  else cout << 'B' << endl;
  

  return 0;
}