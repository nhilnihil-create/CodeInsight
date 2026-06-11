#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n, M;cin>>n>>M;
  vector<vector<int>> c(n, vector<int>(M));
  rep(i, n)rep(j, M){cin>>c[i][j]; c[i][j]--; }

  int result = n;

  rep(i, M){
    map<int, int> m;
    rep(i, n){
      m[c[i][0]]++;
    }
    pi t = {0,0};
    for(pi p: m){
      if(t.second<p.second)t = p;
    }
    rep(i, n)rep(j, c[i].size()){
      if(c[i][j]==t.first) c[i].erase( (c[i].begin()+j) );
    }
    result = min(result, t.second);

//rep(i, n){ rep(j, c[i].size())cout<<c[i][j]<<' ';cout<<endl; } cout<<endl;

  }

  cout<<result<<endl;

  return 0;
}