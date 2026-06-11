#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

struct Lazysegtree{
  int n;
  vector<ll>node,lazy;

  Lazysegtree(vector<ll> v) {
    int sz=v.size();
    n=1;while(n<sz)n*=2;
    node.resize(2*n-1,0);
    lazy.resize(2*n-1,0);
    for(int i=0;i<sz;i++)node[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)node[i]=node[2*i+1]+node[2*i+2];
  }

  void eval(int k,int l,int r){
    if(lazy[k]!=0){
      node[k]+=lazy[k];
      if(r-l>1){
        lazy[2*k+1]+=lazy[k]/2;
        lazy[2*k+2]+=lazy[k]/2;
      }
      lazy[k]=0;
    }
  }

  void update(int x,int val){
    x+=(n-1);
    node[x]=val;
    while(x>0){
      x=(x-1)/2;
      node[x]=node[2*x+1]+node[2*x+2];
    }
  }


  void add(int a,int b,ll x,int k=0,int l=0,int r=-1){
    if(r<0)r=n;
    eval(k,l,r);
    if(b<=l||r<=a)return;
    if(a<=l&&r<=b){
      lazy[k]+=(r-l)*x;
      eval(k,l,r);
    }
    else{
      add(a,b,x,2*k+1,l,(l+r)/2);
      add(a,b,x,2*k+2,(l+r)/2,r);
      node[k]=node[2*k+1]+node[2*k+2];
    }
  }

  ll sum(int a,int b,int k=0,int l=0,int r=-1){
    if(r<0)r=n;
    eval(k,l,r);
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return node[k];

    ll vl=sum(a,b,2*k+1,l,(l+r)/2);
    ll vr=sum(a,b,2*k+2,(l+r)/2,r);
    return vl+vr;
  }

  ll get(int x){
    return sum(x,x+1);
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>p(N);
  for(int i=0;i<N;i++)cin>>p[i];
  for(int i=0;i<N;i++)--p[i];
  vector<ll>A(N),B(N);
  for(int i=0;i<N;i++)A[i]=i+1;
  for(int i=0;i<N;i++)B[i]=N-i;
  Lazysegtree segA(A),segB(B);
  for(int i=0;i<N;i++){
    segA.add(p[i],N,i);
    segB.add(0,p[i]+1,i);
  }
  for(int i=0;i<N;i++)cout<<segA.get(i)<<" ";
  cout<<endl;
  for(int i=0;i<N;i++)cout<<segB.get(i)<<" ";
  cout<<endl;
  return 0;
}
