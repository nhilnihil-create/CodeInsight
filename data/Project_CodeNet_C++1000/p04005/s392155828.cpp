#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e18
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  unsigned long long A, B, C;
  cin >> A >> B >> C;

  unsigned long long MIN = INF;
  unsigned long long sum = A*B*C;

  if(A%2==0||B%2==0||C%2==0){
    cout << 0 << endl;
  }else{
    MIN = min(MIN,A*B);
    MIN = min(MIN,B*C);
    MIN = min(MIN,A*C);
    cout << MIN << endl;
  }
}