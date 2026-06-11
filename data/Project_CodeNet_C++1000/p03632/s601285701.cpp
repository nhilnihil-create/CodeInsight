#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a>c){
    swap(a,c);
  }
  if(d>b){
    swap(b,d);
  }
  int ans=d-c;
  if(d-c>=0){
    cout<<ans<<endl;
  }
  else{
    cout<<0<<endl;
  }
}