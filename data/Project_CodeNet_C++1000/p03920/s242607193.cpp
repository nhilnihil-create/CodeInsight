#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int a;
  int s=0;
  for(int i=1;;i++){
    s+=i;
    if(s>=n){
      a=i;
      break;
    }
  }
  for(int i=1;i<=a;i++){
    if(i!=s-n) cout<<i<<endl;
  }
}