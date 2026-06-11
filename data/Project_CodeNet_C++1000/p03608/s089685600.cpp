#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;

#define MAX_V 300
int d[MAX_V][MAX_V];
int V, M, R;
void warshall_floyd() {
	rep(k, 0, V) rep(i, 0, V) rep(j, 0, V) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

  cin >> V >> M >> R;
  rep(i, 0, V) rep(j, 0, V) d[i][j] = INF;

  int r[R];
  rep(i, 0, R) {
    cin >> r[i];
    --r[i];
  }
  rep(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    d[a][b] = c;
    d[b][a] = c;
  }
  warshall_floyd();

  int array[R];
  rep(i, 0, R) array[i] = i;
  int rsl = INF;
  do {
    int tmp = 0;
    rep(i, 0, R - 1) {
      tmp += d[r[array[i]]][r[array[i + 1]]];
    }
    chmin(rsl, tmp);
  } while (next_permutation(array, array + R));
  cout << rsl << endl;
}

