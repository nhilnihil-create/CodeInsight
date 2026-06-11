#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const int n_max=1e5+1;
vector<int> g[n_max];
int dp[n_max][11];


void paint(int v, int p, int d, int q){
  if(dp[v][d]!=0) return;
  dp[v][d]=q;
  if(d!=0){
    paint(v, p, d-1, q);
    for(auto i:g[v]){
      if(i!=p) paint(i,v,d-1,q);
    }
  }
}



int main(){

  int n,m;
  cin >> n >> m;
  int a[m],b[m];
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
    g[a[i]].pb(b[i]);
    g[b[i]].pb(a[i]);
  }
  rep(i,n)rep(j,11) dp[i][j]=0;
  int q;
  cin >> q;
  int v[q],d[q],c[q];
  rep(i,q) cin >> v[q-1-i] >> d[q-1-i] >> c[q-1-i];
  rep(i,q){
    paint(--v[i],-1,d[i],c[i]);
  }
  rep(i,n) cout << dp[i][0] << endl;
  
  
  return 0;

}
