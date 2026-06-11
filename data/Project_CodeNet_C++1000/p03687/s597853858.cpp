#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  string s;
  cin >> s;
  int N = s.size();

  int MIN = INF;
  FOR(i,'a','z'+1){
    int MAX = 0;
    int p = -1;
    REP(j,s.size()){
      if(i==s.at(j)){
        MAX = max(MAX,j-p-1);
        p=j;
      }
    }
    MAX = max(MAX,N-1-p);
    MIN = min(MAX,MIN);
  }


  cout << MIN << endl;
}