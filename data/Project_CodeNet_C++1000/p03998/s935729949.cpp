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
  string s[3]; cin >> s[0] >> s[1] >> s[2];
  int now = 0;

  while (true){
    //cout << now << " " << s[now] << endl;
    if (s[now] == "") {
      if (now == 0) cout << "A" << endl;
      else if (now == 1) cout << "B" << endl;
      else cout << "C" << endl;
      return 0;
    }
    int tmp = now;
    now = s[now][0] - 'a';
    s[tmp].erase(0, 1);
  }
}
