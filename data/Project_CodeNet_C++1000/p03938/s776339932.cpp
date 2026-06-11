#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20005]={0},b[20005]={0};
int main(){
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++){
    a[i]=i*(n+1);
    b[i]=(n-i+1)*(n+1);
  }
  for(ll i=1;i<=n;i++){
    ll p;
    cin>>p;
    b[p]+=i;
  }
  for(int i=1;i<=n;i++) cout<<a[i]<<" ";
  cout<<endl;
  for(int i=1;i<=n;i++) cout<<b[i]<<" ";
  cout<<endl;
}
