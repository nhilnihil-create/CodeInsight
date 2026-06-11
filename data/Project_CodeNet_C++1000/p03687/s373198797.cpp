#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<bool>    vecbool;
typedef vector<int>     vecint;
typedef vector<ll>      vecll;
typedef vector<string>  vecstr;
typedef vector<vecint>  vec2int;
typedef vector<vecbool> vec2bool;
int dx[4] {-1,+1, 0, 0};
int dy[4] { 0, 0,-1,+1};
int cal(string s, char key){
  int i = 0;
  bool ok = true;
  while(true){
    // cout << s << endl;
    int m = s.size();
    ok = true;
    REP(i,m){
      if(s[i] != key){
	ok = false;
	break;
      }
    }
    if(ok)break;
    ////////////////
    string t = s.substr(0,m - 1);
    for(int j = 1; j < m - 1; j ++){
      if(t[j] == key) t[j - 1] = key;
    }
    s = t;
    i ++;
  }
  return i;
}
int main()
{
  string s; cin >> s;
  int n = s.size();
  int ans = 100;
  REP(i,n){
    ans = min(ans, cal(s,s[i]));
  }
  cout << ans << endl;
}
