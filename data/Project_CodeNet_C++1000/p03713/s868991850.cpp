#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll H,W;
  cin >> H >> W;
  if(H%3==0||W%3==0){
    cout << 0 << endl;
  }else{
    ll ans = min(H,W);
    FOR(i,H/3-5,H/3+5){
      FOR(j,W/2-5,W/2+5){
        if(i<0||i>H-1||j<0||j>W-1) continue;
        ll x = i*W;
        ll y = (H-i)*j;
        ll z = (H-i)*(W-j);
        ll MAX = max(x,max(y,z));
        ll MIN = min(x,min(y,z));
        ans = min(ans,MAX-MIN);
      }
    }
    FOR(i,W/3-5,W/3+5){
      FOR(j,H/2-5,H/2+5){
        if(i<0||i>W-1||j<0||j>H-1) continue;
        ll x = i*H;
        ll y = (W-i)*j;
        ll z = (W-i)*(H-j);
        ll MAX = max(x,max(y,z));
        ll MIN = min(x,min(y,z));
        ans = min(ans,MAX-MIN);
      }
    }

    cout << ans << endl;
  }
}