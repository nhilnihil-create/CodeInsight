#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
ll ans=0;
ll gcd(ll a,ll b){
  if(!b) return ans=ans-a;
  ans+=a/b*b*2;
  gcd(b,a%b);
}
int main(){
    ll n,x;
    cin>>n>>x;
    cout<<gcd(n-x,x)+n;
}