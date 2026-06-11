#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,a1,b1;
  cin>>a>>b;
  if(a==2)a1=1;
  else if(a==4||a==6||a==9||a==11)a1=2;
  else a1=3;
  if(b==2)b1=1;
  else if(b==4||b==6||b==9||b==11)b1=2;
  else b1=3;
  if(a1==b1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}