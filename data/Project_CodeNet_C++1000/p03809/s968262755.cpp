#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

vector<LL> a;
vector<list<int>> e;

struct res{
  LL num;
  int child;
  bool ok;
};

struct res dfs(int n,int parent){
  LL total=0;
  int count=0;
  struct res ans;
  bool ok=true;
  // cout << n << endl;
  list<LL> l;
  for(auto itr=e[n].begin();itr!=e[n].end();itr++){
    if((*itr)!=parent){
      ans=dfs((*itr),n);
      l.push_back(ans.num);
      total+=ans.num;
      ok=ok&&ans.ok;
      count++;
    }
  }
  if(count==0){
    return {a[n],0,true};
  }else if(count==1){
    return {a[n],1,ok&&(total==a[n])};
  }else{
    // cout << total-a[n] << endl;
    int t=0;
    for(auto itr=l.begin();itr!=l.end();itr++){
      t+=max(0,(*itr)-(total-a[n]));
    }
    // cout << t << endl;
    if(t>2*a[n]-total) ok=false;
    return {2*a[n]-total,2,ok&&(2*a[n]-total>=0&&total-a[n]>=0)};
  }
}

int main(){
  int n;
  cin >> n;
  a=vector<LL>(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  e=vector<list<int>>(n,list<int>());
  int u,v;
  for(int i=0;i<n-1;i++){
    cin >> u >> v;
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  struct res ans=dfs(0,-1);
  if(ans.ok&&(ans.child!=2||ans.num==0)){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
