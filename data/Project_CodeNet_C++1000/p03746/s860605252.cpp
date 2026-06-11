#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
  int N, M;cin>>N>>M;
  vi G[N];
  int used[N];
  memset(used, 0, sizeof(used));
  
  for (int i=0;i<M;++i){
    int a, b;cin >>a>>b;
    G[a-1].push_back(b-1);G[b-1].push_back(a-1);
  }

  int cnt=0;
  vi path;
  path.push_back(0);
  used[0]=1;
  int pos=0;

  while(cnt<M){
    int j=0;
    while(used[G[pos][j]]==1&&j<G[pos].size()){j++;}
    int ps=G[pos].size();
    if(j==ps) break;
    int v=G[pos][j];
    path.push_back(v);
    used[v]=1;
    pos=v;
    cnt++;
  }
cnt=0;
  vi path2;
  pos=0;
  while(cnt<M){
    int j=0;
    while(used[G[pos][j]]==1&&j<G[pos].size()){j++;}
    int ps=G[pos].size();
    if(j==ps) break;
    int v=G[pos][j];
    path2.push_back(v);
    used[v]=1;
    pos=v;
    cnt++;
  }

  reverse(path2.begin(), path2.end());

  int L=path2.size();

  path.insert(path.begin(), path2.begin(), path2.end());
  

  int K=path.size();
  cout << K << endl;
  for (int i=0;i<K;++i){
    int v=path[i];
    cout << v+1 << ' ';
  }
  cout << endl;
  return 0;
}
