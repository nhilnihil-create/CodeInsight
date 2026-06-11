#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(b<=c||d<=a) {cout<<0<<endl; return 0;}
  vector<int> x(4);
  x[0]=a;x[1]=b;x[2]=c;x[3]=d;
 sort(x.begin(),x.end());
  cout<<x[2]-x[1]<<endl;
}