#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
 
int main()
{
  int A, B, C;
  cin >> A >> B >> C;

  if(A == B && B == C && A%2 == 0){
    cout << "-1" << endl;
  }else{
    int cnt = 0;
    while(A%2 == 0 && B%2 == 0 && C%2 == 0){
      int a = B/2 + C/2;
      int b = A/2 + C/2;
      int c = B/2 + C/2;
      A = a;
      B = b;
      C = c;
      cnt++;
    }
    cout << cnt << endl;
  }
}