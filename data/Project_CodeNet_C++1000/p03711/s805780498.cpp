#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll x,y;
  cin>>x>>y;
  if(x==2||y==2) {
cout<<"No"<<endl;
  return 0;
  }
  
  set<ll> S;
  S.insert(4);
   S.insert(6);
   S.insert(9);
   S.insert(11);
  
  if(S.count(x)&&!S.count(y)) {
cout<<"No"<<endl;
  }
  else if(!S.count(x)&&S.count(y)) {
cout<<"No"<<endl;
  }
  else {
cout<<"Yes"<<endl;
  }
}