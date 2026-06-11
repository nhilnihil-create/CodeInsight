#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.length();
  rep(i, s.length()) {
    int c = s[i] - 'a';
    if (c == 0) continue;
    if (26 - c <= k) {
      k -= 26 - c;
      s[i] = 'a';
    }
  }
  int c = s[n - 1] - 'a';
  (c += k) %= 26;
  s[n - 1] = 'a' + c;
  cout << s << endl;
}