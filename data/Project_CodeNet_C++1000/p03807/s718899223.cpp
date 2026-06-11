#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  int a,b,c=0;cin>>a;
  rep(i,a){
    cin>>b;
    if(b%2==1)c++;
  }
  if(c%2==0)cout<<"YES";
     else cout<<"NO";
     }