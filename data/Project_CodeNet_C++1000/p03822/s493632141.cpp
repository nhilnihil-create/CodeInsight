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

vector<vector<int> > edge(100005);
int ans[100005];

int solve(int v) {
  vector<int> tmpans;
  for(int i=0;i<edge[v].size();++i) {
    tmpans.push_back(solve(edge[v][i]));
  }
  sort(tmpans.begin(), tmpans.end());
  int ans1=0;
  for(int i=0;i<tmpans.size();++i) {
    ans1 = max(ans1, tmpans[i])+1;
  }
  return ans1;
}

int main() {
  int N;
  cin>>N;
  int tmp;
  for(int i=0;i<N-1;++i) {
    cin>>tmp;
    tmp--;
    edge[tmp].push_back(i+1);
  }
  cout<<solve(0)<<endl;
}

