#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main(){
  ll x; cin >>x;
  ll ans=0;
  ans=x/11*2;
  if (x%11<=6 && x%11!=0) ans+=1;
  else if (6<x%11) ans+=2;
  cout <<ans <<endl;
}
