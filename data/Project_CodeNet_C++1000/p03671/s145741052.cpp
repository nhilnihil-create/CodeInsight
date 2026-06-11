#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  int a,b,c,d;
  cin>>a>>b>>c;
  d=max(a,max(b,c));
  a+=b+c;
  cout<<a-d;
}
