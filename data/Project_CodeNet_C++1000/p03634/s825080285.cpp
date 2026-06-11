#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long a,b,c;
  vector<set<pair<long,long> > >tree(n+1);
  for(int i=0;i<n-1;i++){
    cin >> a >> b >> c;
    tree[a].insert(make_pair(b,c));
    tree[b].insert(make_pair(a,c));
  }
  vector<long>distance(n+1,-1);
  int q,k;
  cin >> q >> k;
  distance[k] = 0;
  queue<int>que;
  que.push(k);
  while(!que.empty()){
    int tmp = que.front();
    que.pop();
    for(auto p: tree[tmp]){
      int dest = p.first;
      int dist = p.second;

      if(distance[dest] == -1){
        distance[dest] = distance[tmp] + dist;
        que.push(dest);
      }
    }
  }
  int x[q];
  int y[q];
  for(int qq = 0;qq<q;qq++){
    cin >> x[qq] >> y[qq];
  }
  for(int i=0;i<q;i++){
    cout << distance[x[i]] + distance[y[i]] << endl;
  }
  
}
