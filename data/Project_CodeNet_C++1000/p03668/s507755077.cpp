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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int N;
vector<vector<int> > edge(100005);
int DP[100005];

int solve(int u, int v) {
  if(DP[u]>-1) return DP[u];
  int ans = 0;
  for(int i=0;i<edge[u].size();++i) {
    if(edge[u][i]==v) continue;
    ans ^= solve(edge[u][i], u)+1;
  }
  return ans;
}

int main() {
  cin>>N;
  int a, b;
  for(int i=0;i<N-1;++i) {
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for(int i=0;i<N;++i) DP[i] = -1;
  if(solve(0, -1)==0) cout<<"Bob"<<endl;
  else cout<<"Alice"<<endl;
}

