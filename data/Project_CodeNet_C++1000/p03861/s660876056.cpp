#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll a,b,x;
  cin>>a>>b>>x;
  if(a%x==0) {
cout<<b/x-a/x+1<<endl;
  }
  else {
cout<<b/x-a/x<<endl;
  }
}
  
  