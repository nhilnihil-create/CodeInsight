/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 200000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

int parent[2][MAX_N+1], depth[MAX_N+1];

int root(int a, int t){
  if(a==parent[t][a])return a;
  return parent[t][a]=root(parent[t][a], t);
}

void unite(int a, int b, int t){
  a=root(a, t);
  b=root(b, t);
  if(depth[a]>depth[b]){
    parent[t][b]=a;
  }else if(depth[b]>depth[a]){
    parent[t][a]=b;
  }else{
    parent[t][a]=b;
    depth[b]++;
  }
}

int main(){
  int n, k, l;cin>>n>>k>>l;
  rep(i, n){
    parent[0][i]=parent[1][i]=i;
    depth[i]=1;
  }
  rep(i, k){
    int p, q;cin>>p>>q;
    unite(--p, --q, 0);
  }
  rep(i, n)depth[i]=1;
  rep(i, l){
    int r, s;cin>>r>>s;
    unite(--r, --s, 1);
  }
  vector<ll> ids(n, 0LL);
  rep(i, n){
    rep(t, 2){
      if(t==0)ids[i]+=ll(root(i, t));
      else ids[i]+=ll(root(i, t))*(MAX_N+1LL);
    }
  }
  map<ll, int> cnt;
  rep(i, n){
    cnt[ids[i]]++;
  }
  rep(i, n){
    // cout<<ids[i]<<" ";
    cout<<cnt[ids[i]]<<" ";
  }
  cout<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
