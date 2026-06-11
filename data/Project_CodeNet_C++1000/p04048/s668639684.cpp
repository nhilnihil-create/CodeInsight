#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)

ll gcd(ll x,ll y){
    if (y==0) return x;
    return gcd(y,x%y);
}

int main(){
  ll n,x;
  cin>>n>>x;
  ll a=gcd(n,x);
  cout<<(n/a-1)*3*a<<endl;
}