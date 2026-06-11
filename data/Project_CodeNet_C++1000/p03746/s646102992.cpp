#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
struct UnionFind {
    int n;
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> group;
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        n=N;
    }
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void calc(){
        group.resize(n,0);
        for(int i=0;i<n;i++){
            group[root(i)]++;
        }
    }
    int size(int x){
        return group[root(x)];
    }
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
 
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
 
};
struct Node{
  int no;
  int par;
  vector<Node*> child;
  void build(int i){
    no=i;par=i;
  }
};
bool judge(Node& node,UnionFind& tree){
    int nm=node.child.size();
    bool res=true;
    rep(i,nm){
        if(!tree.same(node.no,node.child[i]->no))res=false;
    }
    return res;
}
signed main(){
  int n,m;cin>>n>>m;
  vector<Node> node(n+2);
  rep1(i,n){
      node[i].build(i);
  }
  vector<int> res(5*n+100,0);
  UnionFind tree(n+1);
  rep(i,m){
      int a,b;cin>>a>>b;
      if(i==0){
          res[2*n]=a;
          res[2*n+1]=b;
          tree.unite(a,b);
      }
      node[a].child.push_back(&node[b]);
      node[b].child.push_back(&node[a]);
  }
  int cnt=2;
  int cur=2*n;
  int left=res[cur];
  while(!judge(node[left],tree)){
      int nm=node[left].child.size();
      rep(i,nm){
          if(!tree.same(node[left].no,node[left].child[i]->no)){
              --cur;
              tree.unite(node[left].no,node[left].child[i]->no);
              res[cur]=node[left].child[i]->no;
              left=res[cur];
              ++cnt;
              break;
          }
      }
  }
  int right=res[2*n+1];
  cur=2*n+1;
  while(!judge(node[right],tree)){
      int nm=node[right].child.size();
      rep(i,nm){
          if(!tree.same(node[right].no,node[right].child[i]->no)){
              ++cur;
              tree.unite(node[right].no,node[right].child[i]->no); 
              res[cur]=node[right].child[i]->no;
              right=res[cur];
              ++cnt;
              break;
          }
      }
  }
  cout<<cnt<<"\n";
  for(auto& val:res){
      if(val==0)continue;
      cout<<val<<" ";
  }
  cout<<endl;
  return 0;
}