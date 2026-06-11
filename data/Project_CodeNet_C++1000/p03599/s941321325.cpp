#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

bool DP[3005][3005];
double ans = 0;
int I = 0, J = 0;

int main(){
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  DP[0][0] = true;
  for (int i = 0; i <= F; i++){
    for (int j = 0; j <= F; j++){
      if (!DP[i][j]) continue;

      if (i > 0 && ans < (double) j / (double) i) {
        ans = (double)j / (double)i;
        I = i; J = j;
      }

      if (i + 100 * A <= F) DP[i + 100 * A][j] = true;
      if (i + 100 * B <= F) DP[i + 100 * B][j] = true;

      int Water = i - j;
      if (j + C <= Water * E / 100 && j + C <= F){
        DP[i + C][j + C] = true;
      }
      if (j + D <= Water * E / 100 && j + D <= F){
        DP[i + D][j + D] = true;
      }
    }
  }

  if (I == 0 && J == 0) I += 100* A;

  cout << I << " " << J << endl;


  return 0;
}
