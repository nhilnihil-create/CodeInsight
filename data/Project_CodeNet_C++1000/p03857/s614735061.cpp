#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
using namespace std;

struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n, -1) { }
  
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x==y)return false;
    if(par[y]<par[x])swap(x,y);
    par[x]+=par[y];par[y]=x;
    return true;
  }
  
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  
  int size(int x) {
    return -par[root(x)];
  }
  int root(int x) {
    return par[x] < 0 ? x : par[x] = root(par[x]);
  }
};;

map<ll,ll>mama;
signed main(){
  ll n,k,l;
  cin>>n>>k>>l;
  UnionFind uni(n);
  UnionFind uni2(n);
  for(int i=0;i<k;i++){
    int p,q;cin>>p>>q;p--;q--;
    uni.unite(p,q);
  }
  for(int i=0;i<l;i++){
    int p,q;cin>>p>>q;p--;q--;
    uni2.unite(p,q);
  }
  vector<pair<int,int> >num1(n);
  vector<pair<int,int> >num2(n);
  for(int i=0;i<n;i++){
    num1[i]=mp(uni.root(i),uni2.root(i));
    num2[i]=num1[i];
  }
  sort(num1.begin(),num1.end());
  
  int cnt=1;
  for(int i=0;i<n-1;i++){
    while(num1[i].F==num1[i+1].F&&num1[i].S==num1[i+1].S&&i!=n-2){
      cnt++;
      i++;
    }
    if(i==n-2&&num1[i].F==num1[i+1].F&&num1[i].S==num1[i+1].S)
      mama[num1[i].F*(1e6)+num1[i].S]=(cnt+1);
    else {
      mama[num1[i].F*(1e6)+num1[i].S]=(cnt);
      mama[num1[i+1].F*(1e6)+num1[i+1].S]=1;
    }
    cnt=1;
  }
  for(int i=0;i<n;i++){
    cout<<mama[num2[i].F*(1e6)+num2[i].S];
    if(i!=n-1)
      cout<<" ";
  }
  cout<<endl;

  return 0;
}