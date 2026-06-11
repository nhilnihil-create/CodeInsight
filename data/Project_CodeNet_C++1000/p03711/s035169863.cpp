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
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int x, y;
  cin >> x >> y;
  int a[] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  if(a[x] == a[y]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
