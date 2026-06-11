#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;cin>>n;
  ll a[100001*3];
  ll lsums[100001];
  ll rsums[100001];
  lsums[0]=0, rsums[n]=0;

  rep(i,3*n)cin>>a[i];

  priority_queue<ll, vector<ll>, greater<ll>> lq;
  priority_queue<ll> rq;

  rep(i,n){
    lq.push(a[i]);
    lsums[0]+=a[i];

    rq.push(a[3*n-1-i]);
    rsums[n]+=a[3*n-1-i];
  }

  rep(i,n){
    lq.push(a[i+n]);
    lsums[i+1]=(lsums[i]+a[i+n]-lq.top());
    lq.pop();

    rq.push(a[2*n-1-i]);
    rsums[n-1-i]=(rsums[n-i]+a[2*n-1-i]-rq.top());
    rq.pop();
  }


//cout<<lsums[0]<<' '<<rsums[0]<<endl;
  ll result = lsums[0]-rsums[0];
  rep(i,n){
    result=max(result, lsums[i+1]-rsums[i+1]);
  }

  cout<<result;

  return 0;
}
