#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()
#define MAX_V 210

int d[MAX_V][MAX_V];
int N;

int main(){
  int N,M,R;cin>>N>>M>>R;
  vector<int> r(R);rep(i,R){cin>>r[i];r[i]--;}
  rep(i,N)rep(j,N)d[i][j]=1e9;
  rep(i,M){
    int a,b,c;cin>>a>>b>>c;a--,b--;
    d[a][b] = c;
    d[b][a] = c;
  }
  rep(k,N){
    rep(i,N){
      rep(j,N){
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  ll ans = 1e9;
  sort(all(r));
  do{
    ll ans_tmp = 0;
    rep(i,r.size()-1){
      ans_tmp += d[r[i]][r[i+1]];
    }
    ans = min(ans, ans_tmp);
  }while(next_permutation(all(r)));
  cout << ans << endl;
}