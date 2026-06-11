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
  string S; cin >> S;
  int N = S.length();
  vector<int> direct(4, 0);
  rep(i, N){
    if (S[i] == 'W') direct[0]++;
    if (S[i] == 'E') direct[1]++;
    if (S[i] == 'N') direct[2]++;
    if (S[i] == 'S') direct[3]++;
  }
  bool flag = true;
  if (direct[0] != 0) {
    if (direct[1] != 0 && direct[2] == direct[3]) flag = true;
    else flag = false;
  }
  if (direct[1] != 0) {
    if (direct[0] != 0 && direct[2] == direct[3]) flag = true;
    else flag = false;
  }
  if (direct[2] != 0) {
    if (direct[3] != 0 && direct[0] == direct[1]) flag = true;
    else flag = false;
  }
  if (direct[3] != 0) {
    if (direct[2] != 0 && direct[0] == direct[1]) flag = true;
    else flag = false;
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
