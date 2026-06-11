#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll pow(ll x,ll y){
  if(y==0) return 1;
  ll ret=pow(x,y/2);
  ret*=ret;
  if(y%2==1) ret*=x;
  return ret;
}
int main(){
  bool f=false;
  int kt=-1;
  for(int i=0;i<12;i++){
    cout<<"? "<<pow(10,i)<<endl;
    char c;
    cin>>c;
    if(!f&&c=='N'){
      f=true;
      kt=i;
      break;
    }
  }
  if(kt==-1){
    bool f2=false;
    for(int i=1;i<12;i++){
      cout<<"? "<<pow(10,i)-1<<endl;
      char c;
      cin>>c;
      if(!f2&&c=='Y'){
        f=true;
        cout<<"! "<<pow(10,i-1)<<endl;
        return 0;
      }
    }
  }
  ll lb=pow(10,kt),rb=pow(10,kt+1);
  while(rb-lb>1){
    ll mid=(lb+rb)/2;
    cout<<"? "<<mid<<endl;
    char c;
    cin>>c;
    if(c=='Y') rb=mid;
    else lb=mid;
  }
  cout<<"! "<<rb/10<<endl;
  return 0;
}
