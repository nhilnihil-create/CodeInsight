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
  int n,k; cin >> n >> k;
  vi a(n); rep(i,n) cin >> a[i];

  int mx = 0, gcd = a[0];
  rep(i,n){
    chmax(mx,a[i]);
    chmin(gcd,__gcd(gcd,a[i]));
  }
  if(k <= mx && k%gcd == 0) cout << "POSSIBLE";
  else cout << "IMPOSSIBLE";
  cout << "\n";
  return 0;
}
