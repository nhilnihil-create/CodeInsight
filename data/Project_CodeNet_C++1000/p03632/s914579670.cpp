#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z,w;
  cin>>x>>y>>z>>w;
  cout<<max(min(y,w)-max(x,z),0)<<endl;
}