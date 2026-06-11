#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)

#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

char out[1000][1000];
string color = "RYGB";

int main() {
  // ios_base::sync_with_stdio(0);

  int H, W, D;
  scanf("%d%d%d", &H, &W, &D);
  int D2 = 1;
  while (D % (D2<<1) == 0) D2 <<= 1;
  D2 = max(1, D2/2);

  if (D&1) REP(i,H)REP(j,W) out[i][j] = color[(i^j)&1];
  else REP(i,H)REP(j,W) {
    int bit1 = ((i-j + 1000*D)/(D))&1;
    int bit2 = ((i+j)/(D))&1;
    out[i][j] = color[(bit2<<1) + bit1];
  }
  // REP(i,H)REP(j,W) {
    // int bit1 = (i^j^(i/D2)^(j/D2))&1;
    // int bit2 = ((i/D2)^(j/D2))&1;
  // }
  REP(i,H) printf("%s\n", out[i]);
}
