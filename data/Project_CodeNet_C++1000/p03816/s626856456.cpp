#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}


/*{
}*/

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

//constexpr int mod = 1e9+7;
//constexpr int inf = 1<<30;

signed main() {
  int n;
  cin >> n;

  vi a(n);
  rep(i, 0, n) { cin >> a[i]; }

  vi cnt(101010);
  rep(i, 0, n) cnt[a[i]]++;

  vi tmp(2);
  int ans = 0;
  rep(i, 0, 101010) if(cnt[i]){
    tmp[cnt[i]%2]++;
    ans++;
  }

  if(tmp[0]%2) ans = max(0LL, ans-1);
  cout << ans << endl;

  return 0;
}

