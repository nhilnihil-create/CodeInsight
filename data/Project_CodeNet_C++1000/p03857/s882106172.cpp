#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<deque>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<bitset>
#include<time.h>
#include<cstdlib>
#include<cassert>
#define ll long long
#define fi first
#define se second
using namespace std;

int n,k,l;
map<pair<int,int>,int> m;

struct UF{
  int par[200001];
  int Rank[200001];
  void init(int n){
    for(int i=0;i<n;i++){
      par[i]=i;
      Rank[i]=0;
    }
  }
  int Find(int a){
    if(par[a]==a)return a;
    return par[a]=Find(par[a]);
  }
  bool same(int a,int b){
    return Find(a)==Find(b);
  }
  void Unite(int a,int b){
    if(Find(a)==Find(b))return;
    if(Rank[a]>Rank[b]){
      par[b]=a;
    }else{
      par[a]=b;
      if(Rank[a]==Rank[b]){
        Rank[a]++;
      }
    }
  }
  void Union(int a,int b){
    Unite(Find(a),Find(b));
  }
};
                   
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout<<fixed;
#ifdef LOCAL_DEFINE
    freopen("in", "r", stdin); 
    freopen("out","w",stdout);
#endif
  cin>>n>>k>>l;
  UF load,train;
  load.init(n);
  train.init(n);
  for(int i=0;i<k;i++){
    int a,b;cin>>a>>b;
    a--;b--;
    load.Union(a,b);
  }
  for(int i=0;i<l;i++){
    int a,b;cin>>a>>b;
    a--;b--;
    train.Union(a,b);
  }
  for(int i=0;i<n;i++){
    int a=load.Find(i);
    int b=train.Find(i);
    m[pair<int,int>(a,b)]++;
  }
  for(int i=0;i<n;i++){
    int a=load.Find(i);
    int b=train.Find(i);
    cout<<m[pair<int,int>(a,b)];
    if(i!=n-1)cout<<" ";
  }
  cout<<"\n";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}