#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n;
int a[100005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  fill(a, a + n, false);
  int count = 0;
  int mcount = 0;
  REP(i, n) {
    int b;
    cin >> b;
    if(a[b]) {
      mcount++;
    } else {
      count++;
      a[b] = true;
    }
  }

  if(mcount % 2 == 0) cout << count << endl;
  else cout << count - 1 << endl;
}
