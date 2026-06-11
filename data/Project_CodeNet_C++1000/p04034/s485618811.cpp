#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
#include <queue>

using namespace std; using ll=long long; using P=pair<ll,ll>; const int INF=1e9; const ll LNF=1e18;

int main(){
  int n,m; cin>>n>>m;
  int p[n]; bool q[n]={true}; fill(p,p+n,1);

  for(int i=0;i<m;i++) {
    int x,y; cin>>x>>y; x--; y--;
    if (q[x]) {
      if (p[x]==1) {
        q[x]=false; q[y]=true;
      } else {
        q[y]=true;
      }
      p[x]--; p[y]++;
    } else {
      p[x]--; p[y]++;
    }
  }

  int an = 0;
  for(int i=0;i<n;i++) {
    an += q[i];
  }
  cout << an << endl;
}
