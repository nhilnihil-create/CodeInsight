#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(n);++i)
#define MOD 1000000007 
using namespace std;
typedef long long LL;

const int PMAX = 9999;
const int offset = 5000;

int main(){
  int N, MA, MB;
  cin >> N >> MA >> MB;
  vector<int> dp(offset * 2 + 1, PMAX);
  REP(i, N) {
    int A, B, C;
    cin >> A >> B >> C;
    int t = MA * B - MB * A;
    vector<int> ndp(dp);
    REP(j, offset * 2 + 1) {
      if(dp[j] < PMAX) {
        ndp[j+t] = min(dp[j+t], dp[j] + C);
      }
    }
    ndp[offset+t] = min(dp[offset+t], C);
    dp = ndp;
  }
  cout << (dp[offset] == PMAX ? -1 : dp[offset]) << endl;
}