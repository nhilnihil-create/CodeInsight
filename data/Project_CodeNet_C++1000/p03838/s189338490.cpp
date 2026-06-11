#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  ll x,y;
  cin>>x>>y;
  if(x*y<0){
    cout<<abs(abs(x)-abs(y))+1<<endl;
  }else{
    if(0<=x&&x<=y){
      cout<<y-x<<endl;
    }else if(x<=y&&y<=0){
      cout<<y-x<<endl;
    }else if(x==0&&y<0){
      cout<<-y+1<<endl;
    }else if(y==0&&x>0){
      cout<<x+1<<endl;
    }else{
      cout<<abs(abs(x)-abs(y))+2<<endl;
    }
  }
}
