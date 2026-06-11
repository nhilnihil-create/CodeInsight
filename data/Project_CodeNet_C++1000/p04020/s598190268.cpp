#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  ll ans = 0;
  int num = INF;
  rep(i,n){
    if(a[i] == 0) continue;
    if(num+1 == i){
      a[i]--;
      ans++;
    }
    if(a[i] % 2){
      a[i]--;
      num = i;
    }
    ans += a[i]/2;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
