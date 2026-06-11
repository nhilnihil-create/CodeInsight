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
  string s; cin >> s;
  char c = s[0];
  int ans = 0;
  rep(i,s.size()){
    ans += (c!=s[i]);
    c = s[i];
  }
  cout << ans;
  cout << endl;
  return 0;
}
