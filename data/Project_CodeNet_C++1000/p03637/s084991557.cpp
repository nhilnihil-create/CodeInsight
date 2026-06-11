#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  ll num0=0,num1=0,num2=0;
  rep(i,N)
  {
    ll a; cin>>a;
    if(a%4==0) {num2+=1; continue;}
    if(a%2==0) {num1+=1; continue;}
    num0+=1;
  }
  //cout<<num0<<" "<<num1<<" "<<num2<<endl;
  if(num0==0) {cout<<"Yes"<<endl; return 0;}
  if(num2==0) {cout<<"No"<<endl; return 0;}
  if(num1!=0)
  {
    if(num0<=num2) {cout<<"Yes"<<endl; return 0;}
    cout<<"No"<<endl; return 0;
  }
  if(num0<=num2+1) {cout<<"Yes"<<endl; return 0;}
  cout<<"No"<<endl;
  return 0;
}