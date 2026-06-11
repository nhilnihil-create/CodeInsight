#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];
  sort(all(a));
  vector<ll> sum(n+1); rep(i,n) sum[i+1] += sum[i]+a[i];
  int ans = 0;
  for(int i = n-1; 0 <= i; i--){
    if(a[i] <= 2*sum[i]) ans++;
    else break;
  }
  cout << ans+1;
  cout << "\n";
  return 0;
}
