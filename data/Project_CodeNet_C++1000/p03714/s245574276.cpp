#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
	int N;cin>>N;
  vector<ll> a(3*N);
  FOR(i,0,3*N)cin>>a[i];
  priority_queue<ll,vector<ll>,greater<ll>> f;
  priority_queue<ll> b;
  vector<ll> sumf(N+1,0LL),sumb(N+1,0LL);
  FOR(i,0,N){
  	f.push(a[i]);
    sumf[0]+=a[i];
  }
  FOR(i,0,N){
  	ll tmp=f.top();
    if(a[i+N]>tmp){
    	f.pop();
      	f.push(a[i+N]);
        sumf[i+1]=sumf[i]+a[i+N]-tmp;
    }else{
    	sumf[i+1]=sumf[i];
    }
  }
  FOR(i,0,N){
  	b.push(a[3*N-1-i]);
    sumb[0]+=a[3*N-1-i];
  }
  FOR(i,0,N){
  	ll tmp=b.top();
    if(a[2*N-1-i]<tmp){
    	b.pop();
      b.push(a[2*N-1-i]);
      sumb[i+1]=sumb[i]+a[2*N-1-i]-tmp;
    }else{
    	sumb[i+1]=sumb[i];
    }
  }
  ll res =-INF;
  FOR(i,0,N+1){
    res=max(res,sumf[i]-sumb[N-i]);
  }
  cout<<res<<endl;
  return 0;
}