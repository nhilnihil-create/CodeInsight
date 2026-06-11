#include <bits/stdc++.h>
using namespace std;

int main(){
   long  int a,b=1,c=1e9+7,i;
  cin>>a;
  for(i=1;i<=a;i++){
b=b*i%c;
  }
  cout<<b<<endl;
}