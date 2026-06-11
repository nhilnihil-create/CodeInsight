#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,ca=0,cb=0;
  cin>>n;
  ll a[n*3];
  priority_queue<ll> pa,pb;
  for(ll i=0;i<n*3;i++){
    cin>>a[i];
    if(i<n){
      ca+=a[i];
      pa.push(-a[i]);
    }else if(i>=n*2){
      cb+=a[i];
      pb.push(a[i]);
    }
  }
  ll aa[n+1],bb[n+1];
  aa[0]=ca;
  for(ll i=1;i<=n;i++){
    ca+=a[i+n-1];
    pa.push(-a[i+n-1]);
    ca+=pa.top();
    pa.pop();
    aa[i]=ca;
  }
  bb[n]=cb;
  for(ll i=n-1;i>=0;i--){
    cb+=a[i+n];
    pb.push(a[i+n]);
    cb-=pb.top();
    pb.pop();
    bb[i]=cb;
  }
  ll ma=aa[0]-bb[0];
  for(ll i=1;i<=n;i++){
    ma=max(aa[i]-bb[i],ma);
  }
  cout<<ma<<endl;
}
  
  