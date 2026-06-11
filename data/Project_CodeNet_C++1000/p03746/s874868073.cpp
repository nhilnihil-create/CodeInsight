#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  vector<vector<int> > edge(N);
  int A, B;
  for(int i=0;i<M;++i) {
    cin>>A>>B;
    A--;
    B--;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
  map<pair<int, int>, int> amap;
  map<int, int> bmap;
  queue<int> que;
  int state;
  que.push(0);
  vector<int> ans, ans1;
  while(!que.empty()) {
    state = que.front();que.pop();
    if(bmap[state]>0) continue;
    ans.push_back(state+1);
    bmap[state]++;
    for(int i=0;i<edge[state].size();++i) {
      if(amap[mp(state, edge[state][i])]>0) continue;
      if(bmap[edge[state][i]]>0) continue;
      que.push(edge[state][i]);
      amap[mp(state, edge[state][i])]++;
      amap[mp(edge[state][i], state)]++;
      break;
    }
  }
  que.push(0);
  bmap[0] = 0;
  while(!que.empty()) {
    state = que.front();que.pop();
    if(bmap[state]>0) continue;
    ans1.push_back(state+1);
    bmap[state]++;
    for(int i=0;i<edge[state].size();++i) {
      if(amap[mp(state, edge[state][i])]>0) continue;
      if(bmap[edge[state][i]]>0) continue;
      que.push(edge[state][i]);
      amap[mp(state, edge[state][i])]++;
      amap[mp(edge[state][i], state)]++;
      break;
    }
  }
  cout<<ans.size()+ans1.size()-1<<endl;
  for(int i=ans1.size()-1;i>0;--i) cout<<ans1[i]<<" ";
  for(int i=0;i<ans.size();++i) cout<<ans[i]<<" ";
  cout<<endl;
}

