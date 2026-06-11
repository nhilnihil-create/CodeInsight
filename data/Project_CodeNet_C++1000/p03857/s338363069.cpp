#include<bits/stdc++.h>
using namespace std;
const int MAX_N=200009;
bool qw[MAX_N];

struct unionfind{
  int par[MAX_N];
  int myrank[MAX_N];
  int size[MAX_N];
  void init(int n){
    for(int i=1;i<=n;i++){par[i]=i; myrank[i]=0; size[i]=1;}
  }
  int find(int x){
    if(par[x]==x){return x;}
    else{return par[x]=find(par[x]);}
  }
  void unite(int x, int y){
    x=find(x); y=find(y);
    if(x==y){return;}
    if(myrank[x]<myrank[y]){par[x]=y; size[y]+=size[x];}
    else{par[y]=x; size[x]+=size[y];}
    if(myrank[x]==myrank[y]){myrank[x]++;}
  }
  bool same(int x, int y){return find(x)==find(y);}
};

int main(){
  int N,K,L;
  cin >> N >> K >> L;
  vector<int> p(K),q(K),r(L),s(L);
  for(int i=0;i<K;i++)cin >> p[i] >> q[i];
  for(int i=0;i<L;i++)cin >> r[i] >> s[i];
  unionfind D,R,W;
  D.init(N); R.init(N); W.init(N);
  for(int i=0;i<K;i++){D.unite(p[i],q[i]);}
  for(int i=0;i<L;i++){R.unite(r[i],s[i]);}
  vector<pair<int,int>> pa(N);
  for(int i=1;i<=N;i++){pa[i-1]=make_pair(D.find(i),R.find(i));}
  sort(pa.begin(),pa.end());
  map<pair<int,int>,int> ma;
  for(int i=0;i<N;i++){
    int cnt=1;
    while(i+1<N && pa[i].first==pa[i+1].first && pa[i].second==pa[i+1].second){
      i++; cnt++;
    }
    ma[make_pair(pa[i].first,pa[i].second)]=cnt;
  }
  for(int i=1;i<=N;i++){
    cout << ma[make_pair(D.find(i),R.find(i))] << " ";
  }
  cout << endl;
}