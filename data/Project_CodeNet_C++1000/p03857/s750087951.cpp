#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007
 
int n,k,l;
 
const int MAX_N=200001;
 
int par1[MAX_N]; //　親
int rank1[MAX_N]; // 木の深さ
int par2[MAX_N];
int rank2[MAX_N];
 
 
// ｎ要素で初期化
void init(){
  for(int i=0;i<n;i++){
    par1[i]=par2[i]=i;
    rank1[i]=rank2[i]=0;
  }
}
 
// 木の根を求める
int find(int x, bool flag){
  if(flag){
    if (par1[x] == x){
      return x;
    }else{
      return par1[x] = find(par1[x],flag);
    }
  }else{
    if(par2[x]==x){
      return x;
    }else{
      return par2[x]=find(par2[x],flag);
    }
  }
}
 
// ｘとｙの属する集合を併合
void unite(int x, int y, bool flag){
  x = find(x,flag);
  y = find(y,flag);
  if (x == y) return;
  if(flag){
    if (rank1[x] < rank1[y]){
      par1[x] = y;
    }else{
      par1[y] = x;
      if (rank1[x] == rank1[y]) rank1[x]++;
    }
  }else{
    if(rank2[x]<rank2[y]){
      par2[x]=y;
    }else{
      par2[y]=x;
      if(rank2[x]==rank2[y]) rank2[x]++;
    }
  }
}
 
// ｘとｙが同じ集合に属するかどうか
bool same(int x, int y, bool flag){
  return find(x,flag) == find(y,flag);
}
 
 
int main(){
  cin>>n>>k>>l;
  init();
  for(int i=0;i<k;i++){
    int p,q;
    cin>>p>>q;
    unite(p-1,q-1,1);
  }
  for(int i=0;i<l;i++){
    int p,q;
    cin>>p>>q;
    unite(p-1,q-1,0);
  }
  //for(int i=1;i<=n;i++) cout<<par1[i]<<" "<<par2[i]<<endl;
  int num[n]={};
  vector<pair<pair<int,int>, int>> v;
  for(int i=0;i<n;i++){
    v.push_back({{find(i,1),find(i,0)}, i});
  }
  sort(v.begin(),v.end());
  int count=1, ind=0;
  for(int i=1;i<n;i++){
    if(v[i].first==v[i-1].first){
      count++;
    }else{
      for(int j=ind;j<i;j++){
        num[v[j].second]+=count;
      }
      ind=i;
      count=1;
    }
  }
  for(int i=ind;i<n;i++){
    num[v[i].second]+=count;
  }
  for(int i=0;i<n-1;i++){
    cout<<num[i]<<" ";
  }
  cout<<num[n-1]<<endl;
  return 0;
}