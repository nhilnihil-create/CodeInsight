#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define P pair<int,int>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int a,b,c; cin >> a >> b >> c;
  if(a%2 || b%2 || c%2){
    cout << 0 << endl;
    return 0;
  }
  if(a == b && b == c && c == a){
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  while(1){
    if(a%2 || b%2 || c%2) break;
    int x = a/2, y = b/2, z = c/2;
    a = y+z;
    b = x+z;
    c = x+y;
    ans++;
  }
  cout << ans;
  cout << endl;
  return 0;
}
