#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin>>n;
  ll a,b,ma=0,mb;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    ma=max(ma,a);
    if(ma==a){
      mb=b;
    }
  }
  while(mb>0){
    mb--;
    ma++;
  }
  cout<<ma<<endl;
}