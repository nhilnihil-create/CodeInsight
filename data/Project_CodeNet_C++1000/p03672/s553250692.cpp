#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  string S;
  cin >> S;
  int ans = 0;
  for(int i=sz(S)-1;i>=1;i--){
    string str=S.substr(0,i);
    if(sz(str)%2==0&&str.substr(0,sz(str)/2-1)==str.substr(sz(str)/2,sz(str)/2-1)){
      ans=i;
      break;
    }
  }

  cout << ans << endl;
}