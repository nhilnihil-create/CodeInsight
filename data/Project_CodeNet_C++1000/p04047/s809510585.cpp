#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  int a,c=0;cin>>a;
  vector<int>b(2*a);
  rep(i,2*a)cin>>b[i];
  sort(b.begin(),b.end());
  for(int i=0;i<2*a;i+=2){
    c+=b[i];
  }
  cout<<c;
}
