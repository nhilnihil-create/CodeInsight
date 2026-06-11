#include <bits/stdc++.h>
using namespace std;

int main() {
  long q,h,s,d,n,ans=0;
  cin >> q >> h >> s >> d >> n;
  h=min(h,q*2);
  s=min(s,h*2);
  d=min(d,s*2);
  cout << d*(n/2)+s*(n%2) << endl;
}