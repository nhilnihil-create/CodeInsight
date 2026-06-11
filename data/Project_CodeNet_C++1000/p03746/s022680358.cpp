#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];

bool is[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int a, b;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  int node = 1;
  is[node] = true;
  deque<int> ff;
  ff.push_back(node);
  bool ok = true;
  while(ok){
    ok = false;
    node = ff.front();
    for(auto x : T[node]){
      if(!is[x]){
        ff.push_front(x);
        is[x] = true;
        ok = true;
        break;
      }
    }
    node = ff.back();
    for(auto x : T[node]){
      if(!is[x]){
        ff.push_back(x);
        is[x] = true;
        ok = true;
        break;
      }
    }
  }
  cout << ff.size() << "\n";
  while(!ff.empty()){
    cout << ff.front() << " ";
    ff.pop_front();
  }
  return 0;
}