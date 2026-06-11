#include <bits/stdc++.h>
using namespace std;
int i,j,a,b,c,n,m,k,l;
int main(){
  for(cin>>a>>b,i=a;i<=b;i++){
    if(i==0)return cout<<"Zero",0;
    if(i<0)c++;
  }
  cout<<(c&1?"Negative":"Positive");
}