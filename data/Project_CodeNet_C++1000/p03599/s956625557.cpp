#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>
#include <bitset>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  double A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;

  double max_concentration = -1;
  double mass_all = 0, mass_sugar = 0;
  for (int i = 0; i < 35; ++i){
    for (int j = 0; j < 35; ++j){
      for (int k = 0; k < 3100; ++k){
        if (100 * A * i + 100 * B * j + C * k > F) continue;
        for (int m = 0; m < 3100; ++m){
          if (100 * A * i + 100 * B * j + C * k + D * m <= F && C * k + D * m <= E * (A * i + B * j)) {
            double a = 100 * A * i + 100 * B * j, b = C * k + D * m;
            double concentration = (100 * b) / (a + b);
            if (chmax(max_concentration, concentration)){
              mass_all = a + b;
              mass_sugar = b;
            }
          }
        }
      }
    }
  }
  cout << mass_all << " " << mass_sugar << endl;
}
