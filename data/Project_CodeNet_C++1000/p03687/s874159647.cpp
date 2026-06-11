#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  string s; cin >> s;
  vi dist(26,-1);
  for(char a = 'a'; a <= 'z'; a++){
    int cnt = 0;
    rep(i,s.size()){
      if(s[i] == a){
        chmax(dist[a-'a'],cnt);
        cnt = 0;
      }else cnt++;
    }
    chmax(dist[a-'a'],cnt);
  }
  // rep(i,26) cout << char('a'+i) << ":" << dist[i] << endl;
  int ans = 1001001001;
  rep(i,26) chmin(ans,dist[i]);
  cout << ans;
  cout << "\n";
  return 0;
}
