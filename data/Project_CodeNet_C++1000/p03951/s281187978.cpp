#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int N;
  cin >> N;
  string s, t;
  cin >> s >> t;

  string ans = s;
  REPR(i,N){
    int flag = 0;
    REP(j,i){
      if(s.at(j+N-i)!=t.at(j)){
        flag = 1;
      }
    }
    if(flag==0){
      cout << 2*N-i << endl;
      break;
    }
  }
}