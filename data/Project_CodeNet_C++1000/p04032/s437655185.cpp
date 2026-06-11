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
const int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  int l = -1, r = -1;
  rep(i, n - 2) {
    if(s[i] == s[i + 1] || s[i + 1] == s[i + 2] || s[i + 2] == s[i]) l = i, r = i + 2;
  }
  rep(i, n - 1) {
    if(s[i] == s[i + 1]) l = i, r = i + 1;
  }
  if(l == -1) cout << l << " " << r << endl;
  else cout << l + 1 << " " << r + 1 << endl;
}