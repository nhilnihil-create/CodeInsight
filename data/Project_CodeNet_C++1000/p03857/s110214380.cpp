#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define MAXN 200010
vector<ll> c(MAXN,1);
ll par[MAXN]; // 親
ll deep[MAXN]; // 深さ

// in要素で初期化
ll init(ll in){
  for(int i=0;i<=in;i++){
    par[i]=i;
    deep[i]=0;
  }
}

// 木の根を求める
ll find(ll x){
  if(par[x]==x){
    return x;
  }else{
    return par[x]=find(par[x]);
  }
}

// xとyの集合を併合
void unite(ll x,ll y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(deep[x]<deep[y]){
    par[x]=y;
  }else{
    par[y]=x;
    if(deep[x]==deep[y]) deep[x]++;
  }
}

// xとyが同じ集合に属するか否か
bool same(ll x,ll y){
  return find(x)==find(y);
}

ll pard[MAXN]; // 親
ll deepd[MAXN]; // 深さ

// in要素で初期化
ll initd(ll in){
  for(int i=0;i<=in;i++){
    pard[i]=i;
    deepd[i]=0;
  }
}

// 木の根を求める
ll findd(ll x){
  if(pard[x]==x){
    return x;
  }else{
    return pard[x]=findd(pard[x]);
  }
}

// xとyの集合を併合
void united(ll x,ll y){
  x=findd(x);
  y=findd(y);
  if(x==y) return;
  if(deepd[x]<deepd[y]){
    pard[x]=y;
  }else{
    pard[y]=x;
    if(deepd[x]==deepd[y]) deepd[x]++;
  }
}

// xとyが同じ集合に属するか否か
bool samed(ll x,ll y){
  return findd(x)==findd(y);
}

int main(){
  ll n,k,l,p,q;
  cin>>n>>k>>l;
  init(n); initd(n);
  for(int i=0;i<k;i++){
    cin>>p>>q;
    unite(p,q);
  }
  for(int i=0;i<l;i++){
    cin>>p>>q;
    united(p,q);
  }
  for(int i=1;i<=n;i++){
    find(i);
    findd(i);
  }
  map<P,ll> mp;
  for(int i=1;i<=n;i++){
    mp[P(par[i],pard[i])]++;
  }
  for(int i=1;i<=n;i++){
    cout<<mp[P(par[i],pard[i])]<<" ";
  }
}
