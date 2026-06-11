#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int s=max(a,c);
  int e=min(b,d);
  cout<<max(0,e-s);

}
