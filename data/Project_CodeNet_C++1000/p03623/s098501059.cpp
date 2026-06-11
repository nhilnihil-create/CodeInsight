#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll a,b,x;
  cin>>x>>a>>b;
  ll A=abs(x-a);
  ll B=abs(x-b);
  if(A>B) {
cout<<'B'<<endl;
  }
  else {
cout<<'A'<<endl;
  }
}