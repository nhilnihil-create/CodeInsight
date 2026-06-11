#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;

signed _main(){
  string S; cin >> S;
  map<char,int> mp;
  int answer=INF;
  rep(i,S.size()){
    mp[S[i]]++;
  }
  fore(g,mp){
    char c=g.first;
    int ans=0;
    string s=S;
    while(1){
      int cnt=0;
      rep(i,s.size()){
        if(s[i]==c) cnt++;
      }
      if(cnt==s.size()){
        //cout << ans << endl;
        chmin(answer,ans);
        break;
      }
      for(int i=1;i<s.size();i++){
        if(s[i]==c){
          s[i-1]=c;
        }
      }
      s.pop_back();
      ans++;
    }
  }
  cout << answer << endl;
  return 0;
}
