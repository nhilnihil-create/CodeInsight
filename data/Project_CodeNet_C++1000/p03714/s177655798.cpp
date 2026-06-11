#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,int>>>;
using pp=pair<int,pair<int,int>>;
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N;
  cin>>N;
  vector<ll> a(3*N);
  for(int i=0;i<3*N;i++){
    cin>>a[i];
  }

  priority_queue<ll,vector<ll>,greater<ll>> pq;
  vector<ll> M(N+1,0);
  for(int i=0;i<N;i++){
    M[0]+=a[i];
    pq.push(a[i]);
  }
  for(int i=0;i<N;i++){
    M[i+1]=M[i];
    pq.push(a[i+N]);
    M[i+1]+=a[i+N];
    ll x=pq.top();
    pq.pop();
    M[i+1]-=x;
  }

  priority_queue<ll> pq2;
  vector<ll> m(N+1,0);
  for(int i=0;i<N;i++){
    m[N]+=a[i+2*N];
    pq2.push(a[i+2*N]);
  }
  for(int i=0;i<N;i++){
    m[N-i-1]=m[N-i];
    pq2.push(a[2*N-i-1]);
    m[N-i-1]+=a[2*N-i-1];
    ll x=pq2.top();
    pq2.pop();
    m[N-i-1]-=x;
  }

  ll ans=M[N]-m[N];
  for(int i=0;i<N;i++){
    ans=max(ans,M[i]-m[i]);
  }
  cout<<ans<<endl;
}
