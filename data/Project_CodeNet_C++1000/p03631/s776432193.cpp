#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int a,b[2];
  cin>>a;
  b[1]=a/100;
  b[0]=a%10;
  if(b[1]==b[0]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}