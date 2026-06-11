#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main(){
  ll x,y,z;
  cin>>x>>y;
  z=y;
  for(int w=1;w<x;w++) z*=y-1;
  cout<<z<<endl;
}