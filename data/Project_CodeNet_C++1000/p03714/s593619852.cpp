#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 9223372036854775807
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for(long long i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  ll fsum[n+1],bsum[n+1];
  ll sum = 0;
  
  priority_queue <int,vector<int>,greater<int>>f;
  priority_queue <int>b;
  vector <int>a(3*n);
  REP(i,3*n){
    cin >> a[i];
  }
  
  REP(i,n){
    f.push(a[i]);
    sum += a[i];
  }
  fsum[0] = sum;
  
  REP(i,n){
    f.push(a[n+i]);
    sum += a[n+i]-f.top();
    fsum[i+1] = sum;
    f.pop();
  }
  
  sum = 0;
  
  FOR(i,2*n,3*n){
    b.push(a[i]);
    sum += a[i];
  }
  bsum[n] = sum;
  
  REP(i,n){
    b.push(a[2*n-1-i]);
    sum += a[2*n-1-i]-b.top();
    bsum[n-i-1] = sum;
    b.pop();
  }

  ll ans = -INF;
  REP(i,n+1){
    ans = max(ans,fsum[i]-bsum[i]);
 //   cout << fsum[i] << " " << bsum[i] << endl;
  }
  
  cout << ans << endl;

  return 0;
}