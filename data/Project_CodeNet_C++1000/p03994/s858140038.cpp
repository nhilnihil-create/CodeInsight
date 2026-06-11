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
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;

signed _main(){
  string s; int K;
  cin >> s >> K;
  v<int> cnt(s.size());
  rep(i,s.size()){
    cnt[i]='z'-s[i]+1;
  }
  int index=0;
  while(index<s.size()){
    if(s[index]=='a'){
      index++;
      continue;
    }
    if(cnt[index]<=K){
      s[index]='a';
      K-=cnt[index];
    }
    index++;
  }
  K%=26;
  int num=s[s.size()-1]-'a'+K;
  if(num<=26) s[s.size()-1]='a'+num;
  else s[s.size()-1]='a'+num-26;
  cout << s << endl;
  return 0;
}
