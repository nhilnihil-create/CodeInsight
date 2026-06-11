#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main()
{
  string s; cin >> s;
  
  reverse(ALL(s));
  REP(i,4) reverse(ALL(divide[i]));
  
  bool can = true;
  for(int i = 0;i < s.size();){
    bool can2 = false;
    REP(j,4){
      string d = divide[j];
      if(s.substr(i,d.size())==d){
        can2 = true;
        i += d.size();
      }
    }
    if(!can2){
      can = false;
      break;
    }
  }
  
  if (can) cout << "YES" << endl;
  else cout << "NO" << endl;
}