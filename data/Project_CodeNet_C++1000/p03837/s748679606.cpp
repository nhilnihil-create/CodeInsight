#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int INF=1001001001;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<P>> Ni(n, vector<P>(0));
  vector<int> Mi(m);
  for(int i=0; i<m; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    Ni[a].push_back(make_pair(b,i));
    Ni[b].push_back(make_pair(a,i));
    Mi[i] = c;
  }
  priority_queue<P,vector<P>,greater<P>> que;
  map<int, bool> usedMi;
  for(int i=0; i<n; ++i){
    que.push(make_pair(0, i));
    vector<int> minc(n,INF);
    minc[i] = 0;
    while(!que.empty()){
      int c, xi;
      tie(c,xi) = que.top();
      que.pop();
      if(minc[xi] < c) continue;
      for(P pi : Ni[xi]){
        if(c+Mi[pi.second] < minc[pi.first]){
          minc[pi.first] = c+Mi[pi.second];
          que.push(make_pair(c+Mi[pi.second],pi.first));
        }
      }
    }
    queue<int> que2;
    vector<bool> seached(n,true);
    que2.push(i);
    while(!que2.empty()){
      int x = que2.front();
      que2.pop();
      seached[x] = false;
      for(P pi : Ni[x]){
        if(seached[pi.first] && minc[pi.first] == minc[x] + Mi[pi.second]){
          usedMi[pi.second] = true;
          que2.push(pi.first);
        }
      }
    }
  }
  cout << m - usedMi.size() << endl;
}