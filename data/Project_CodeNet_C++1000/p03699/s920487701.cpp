#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i= (a); i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() { int N;
  cin >> N;
  vector<int> s(N);
  REP(i, N) cin >> s[i];
  sort(s.begin(), s.end());
  ll mx = 0;
  REP(i, N) mx += s[i];
  int i = 0;
  while(true){
    if (mx % 10 != 0) break;
    mx -= s[i];
    i++;
    if(i==N){
      break;
    }
  }
  for (int j = i-1; 0<=j ;j--){
    if ((mx + s[j]) % 10 != 0) mx += s[j];
  } cout << mx << endl;
}