#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
vector<int> G[N];
int num[N];

int can(int pos,int par){
  int sum = 0,mx = 0;
  for(int to:G[pos]) if(to!=par) sum += num[to],Max(mx,num[to]);
  int mxpair = sum-mx < mx? (sum-mx): sum/2;
  if(sum < num[pos]) return 0;

  int target = sum - num[pos];
  if(mxpair < target) return 0;
  num[pos] = num[pos] - target;
  return 1;
}

int check(int pos,int par){
  if(par != -1 && G[pos].size() == 1) return 1;

  int res = 1;  
  for(int to:G[pos]) if(to != par)res &= check(to,pos);
  res &= can(pos,par);
  return res;
}

signed main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>num[i];
  
  for(int i=0,a,b;i<n-1;i++){
    cin>>a>>b;  a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int root = 0;
  for(int i=0;i<n;i++) if(G[i].size() == 1) root = i;
  int ans = check(root,-1);
  cout<<(ans? "YES":"NO")<<endl;
  return 0;
}
