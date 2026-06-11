#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll gcd(ll a,ll b){
  if(a%b==0)return b;
  else return gcd(b,a%b);
}

int main(){
  ll n;cin>>n;
  ll tmp1;
  cin>>tmp1;
  ll tmp2;
  for(int i=1;i<n;i++){
    cin>>tmp2;
    tmp1=tmp1/gcd(tmp1,tmp2)*tmp2;
  }
  cout <<tmp1<<endl;
}