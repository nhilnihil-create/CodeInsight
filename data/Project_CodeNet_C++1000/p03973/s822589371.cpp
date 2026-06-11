#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans=a[0]-1;
  ll u=2;
  for (int i=1;i<n;i++){
    if (a[i]<u) continue;
    if (a[i]==u){
      u++;
      continue;
    }
    ans+=(a[i]-1ll)/u;
  }
  cout << ans << endl;
}
