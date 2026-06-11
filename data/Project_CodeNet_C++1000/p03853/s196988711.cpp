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
  int H, W;
  cin >> H >> W;

  vector<string> C(H);
  REP(i, H) cin >> C[i];
  
  REP(i,H){
    cout << C.at(i) << endl;
    cout << C.at(i) << endl;
  }
}