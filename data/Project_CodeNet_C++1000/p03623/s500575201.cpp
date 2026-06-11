#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  if(abs(x-y)<abs(x-z)) cout<<'A'<<endl;
  else cout<<'B'<<endl;
}