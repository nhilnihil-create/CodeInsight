#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a; i<n; i++)
using namespace std;;
 
int main() {
  int N,M; cin >> N >> M;
  vector<pair<int,int>> pair(M);
  rep(i,0,M) {
    int a,b; cin >> a >> b;
    pair[i] = make_pair(a,b);
  }
   
  map<int,int> secondS;
  vector<int> firstS;
  for(auto x: pair) {
    if(x.first == 1) firstS.push_back(x.second);
    if(x.second == N) secondS[x.first]=1;
  }
  
  int size = secondS.size();
  for(int x: firstS) {
    if (secondS[x] == 1) {
        cout << "POSSIBLE" << endl; return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}