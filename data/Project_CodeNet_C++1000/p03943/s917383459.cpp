#include<iostream>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if (b>a) swap(a,b);
  if (c>a) swap(a,c);
  if (a==b+c) cout<<"Yes";
  else cout<<"No";
  return 0;
}