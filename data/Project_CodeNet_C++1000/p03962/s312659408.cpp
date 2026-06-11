#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;cin>>a>>b>>c;
  int ans = 3;
  if(a==b && b==c) ans=1;
  else if(a==b || b==c || c==a) ans--;
  cout << ans << endl;
}
