#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int x,y;cin>>x>>y;
  if(x==4||x==6||x==9||x==11) x=3;
  else if(x==2) x=4;
  else x=2;
  
  if(y==4||y==6||y==9||y==11) y=3;
  else if(y==2) y=4;
  else y=2;
  
  if(x==y) cout << "Yes" << endl;
  else cout << "No" << endl;
}
