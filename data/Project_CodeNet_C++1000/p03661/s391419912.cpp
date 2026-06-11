#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N;
  cin >> N;
  ll a[N];
  rep(i,N) cin >> a[i];
  ll sum[N];
  sum[0] = a[0];
  rep1(i,N-1) sum[i] = sum[i-1]+a[i];
  ll ans=INT_MAX*1LL;
  rep(i,N-1) ans =min(abs((sum[N-1]-sum[i])-sum[i]) ,ans);
  cout << ans << endl;
  return 0;
    

}
