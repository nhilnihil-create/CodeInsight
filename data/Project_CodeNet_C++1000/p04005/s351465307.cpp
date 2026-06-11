#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  if(a>b)swap(a,b);
  if(b>c)swap(b,c);
  if(a>b)swap(a,b);
  if(a%2==0||b%2==0||c%2==0)cout<<0;
  else{
    cout<<a*b;
  }
}