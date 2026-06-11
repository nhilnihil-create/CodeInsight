#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll a[3];
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  sort(a,a+3);
  
  ll count=1;
  for(int i=0;i<2;i++){
    if(a[i]!=a[i+1]){
      count++;
    }
  }
  
  cout<<count<<endl;
  return 0;
}