#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,a,b,c,d;
  string ans="NO";
  cin >> n >> a >> b >> c >> d;
  for(long i=0;i<n;i++) {
    if((b-a>=(i*c)-((n-i-1)*d))&&(b-a<=(i*d)-((n-i-1)*c))) ans="YES";
  }
  cout << ans << endl;
}