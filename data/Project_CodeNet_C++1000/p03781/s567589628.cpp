#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin>>X;
  int i=0;
  for(int j=0;j<X;i++,j+=i){}
  cout<<i<<endl;
}