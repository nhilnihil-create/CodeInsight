#include <bits/stdc++.h>
using namespace std;

#define int long long
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int a,b;cin>>a>>b;
  if(a*b<=0)fin("Zero");
  if(a>0)fin("Positive");
  if((b-a)&1)fin("Positive");
  fin("Negative");
}
