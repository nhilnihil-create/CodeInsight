#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000007
typedef long long int lint;

int main() {
  int N,now,ans = mod,av = 0;
  cin >> N;
  vector<int> a(N);
  rep(i,0,N){cin >> a[i]; av += a[i];}
  sort(a.begin(),a.end());
  av /= N;
  
  if(a[N/2] >= av){
    rep(i,av-1,a[N/2] + 2){
      now = 0;
      rep(j,0,N){
        now += (i - a[j])*(i - a[j]);
      }
      ans = min(ans,now);
    }
    co(ans);
  }
  else{
    rep(i,a[N/2]-1,av + 2){
      now = 0;
      rep(j,0,N){
        now += (i - a[j])*(i - a[j]);
      }
      ans = min(ans,now);
    }
    co(ans);
  }
  return 0;
}