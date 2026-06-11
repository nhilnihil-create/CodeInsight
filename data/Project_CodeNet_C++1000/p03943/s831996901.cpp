#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  if(a+b==c||b+c==a||c+a==b) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}