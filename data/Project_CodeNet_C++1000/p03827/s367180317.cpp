#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,x=0,ans=0;
  string s;
  cin >> n >> s;
  for(long i=0;i<n;i++) {
    if(s[i]=='I') x++;
    else x--;
    ans=max(ans,x);
  }
  cout << ans << endl;
}