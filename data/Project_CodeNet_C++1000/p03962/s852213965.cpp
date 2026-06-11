#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  int a,b,c,d=3;cin>>a>>b>>c;
  if(a==b)d--;
  if(b==c)d--;
  if(a==c)d--;
  if(a==b&&a==c)d++;
  cout<<d;
}
