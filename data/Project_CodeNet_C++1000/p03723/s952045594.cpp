#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
ll a,b,c,d;
int main(){
  cin>>a>>b>>c;
  if(!(a&1)&&a==b&&b==c)return cout<<-1,0;
  while(!(a&1)&&!(b&1)&&!(c&1)){
    d++;
    a/=2;
    b/=2;
    c/=2;
    ll a1=b+c;
    ll b1=a+c;
    ll c1=b+a;
    a=a1,b=b1,c=c1;
  }
  cout<<d<<endl;
}