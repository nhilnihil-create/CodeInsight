#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  int f = 0, b = 0, o = 0;
  rep(i,n){
    cin>>a.at(i);
    if(a.at(i)%4==0)f++;
    else if(a.at(i)%2==0)b++;
    else o++;
  }
  int flag = 0;
  if(b>=2){
    if(f>=o)flag = 1;
  }else{
    o+=b;
    if(f>=o-1)flag = 1;
  }
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}