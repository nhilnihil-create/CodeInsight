#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int x=min(a+b,b+c);
  int y=min(x,a+c);
  cout<<y<<endl;
}