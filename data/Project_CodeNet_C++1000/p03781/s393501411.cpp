#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,time,sum=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    sum+=i;
    if(sum>=n){
      time = i;
      break;
    }
  }
  cout<<time<<endl;
}
