#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define all(a) a.begin(),a.end()
typedef pair<int,int> P;
constexpr long long mod=1000000007;
constexpr long long inf=1ll<<61;
struct segtree{
  vector<int>node,lazy;
  int n;
  void init(int N){
    n=1;
    while(n<N)n*=2;
    node.resize(n*2);
    lazy.resize(n*2);
  }
  void eval(int k,int l,int r){
    if(!lazy[k])return;
    node[k]+=lazy[k]*(r-l);
    if(k<n-1){
      lazy[2*k+1]+=lazy[k];
      lazy[2*k+2]+=lazy[k];
    }
    lazy[k]=0;
  }
  void update(int a,int b,int x,int k,int l,int r){
    eval(k,l,r);
    if(r<=a||b<=l)return;
    if(a<=l&&r<=b){
      lazy[k]=x;
      eval(k,l,r);return;
    }
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
    node[k]=node[k*2+1]+node[k*2+2];
  }
  int calc(int a,int b,int k,int l,int r){
    eval(k,l,r);
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return node[k];
    int vl=calc(a,b,k*2+1,l,(l+r)/2);
    int vr=calc(a,b,k*2+2,(l+r)/2,r);
    return vl+vr;
  }
  void add(int a,int b,int x){
    update(a,b,x,0,0,n);
  }
  int getsum(int a,int b){
    return calc(a,b,0,0,n);
  }
};

vector<P>seg[100006];
int ans[100006];
segtree S;
signed main(){
  int n,m;cin>>n>>m;
  rep(i,n){
    int l,r;cin>>l>>r;
    seg[r-l+1].push_back(P(l,r));
  }
  int unused=n;
  S.init(m+1);
  for(int i=1;i<=m;i++){
    ans[i]+=unused;
    unused-=seg[i].size();
    for(int j=i;j<=m;j+=i){
      ans[i]+=S.getsum(j,j+1);
    }
    for(auto e:seg[i]){
      S.add(e.first,e.second+1,1);
    }
  }
  rep(i,m)cout<<ans[i+1]<<endl;
}