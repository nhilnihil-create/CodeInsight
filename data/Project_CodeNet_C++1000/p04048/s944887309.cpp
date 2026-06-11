#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,X;
  cin>>N>>X;
  cout<<3*(N-__gcd(N,X))<<endl;
}