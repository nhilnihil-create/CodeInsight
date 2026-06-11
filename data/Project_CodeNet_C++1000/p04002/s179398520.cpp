#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1e18;
const ll mod = 1e9 + 7;

map<pll, ll> cnt;
map<ll, ll> ans;

int main()
{
  ll h, w, n;
  cin >> h >> w >> n;

  rep(i, n){
    ll a, b;
    cin >> a >> b;

    for(int j = max(1LL, a-2); j <= min(h-2, a); j++){
      for(int k = max(1LL, b-2); k <= min(w-2, b); k++){
        cnt[mp(j, k)]++; 
      }
    }
  }

  for(auto u : cnt){
    ans[u.second]++;
  }

  ll sum = 0;
  for(int i = 1; i < 10; i++) sum += ans[i];

  cout << (h-2)*(w-2)-sum << endl;
  for(int i = 1; i < 10; i++) cout << ans[i] << endl;
  
  return 0;
}
