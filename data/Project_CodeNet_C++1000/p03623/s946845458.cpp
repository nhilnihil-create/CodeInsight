#include<bits/stdc++.h>
using namespace std;
int main(){
int x,a,b;
  cin>>x>>a>>b;
  int d1=abs(a-x);
  int d2=abs(b-x);
  if(d1<=d2)
    cout<<'A'<<endl;
  else
    cout<<'B'<<endl;
   return 0;
}