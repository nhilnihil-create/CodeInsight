#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
  int N;
  cin >> N;
  vector<ll>cnt(100100,0);
  rep(i,N){
    int a;
    cin >> a;
    cnt[a]++;
  }
  ll ans=0;
  for(int i=0;i<=100010;i++){
    ll sum=0;
    if(i-1>=0)sum+=cnt[i-1];
    sum+=cnt[i];
    if(i+1<100100)sum+=cnt[i+1];
    ans=max(ans,sum);
  }
  cout << ans << endl;
  return 0;
}