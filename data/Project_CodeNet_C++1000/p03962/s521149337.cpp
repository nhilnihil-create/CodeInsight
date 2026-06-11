#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  int s=1;
  
  if(a!=b)s++;
  if(a!=c&&b!=c)
    s++;
  cout<<s<<endl;
}