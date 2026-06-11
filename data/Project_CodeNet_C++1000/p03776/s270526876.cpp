#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

// before your coding, you have to write a line "math_init()"
lint COM[52][52] = {};

void com_init() {
  COM[0][0] = 1;
  for (int i = 0; i <= 50; i++) {
    for (int j = 0; j <= 50; j++) {
      COM[i + 1][j] += COM[i][j];
      COM[i + 1][j + 1] += COM[i][j];
    }
  }
}

int main() {

  com_init();
  
  lint n, a, b; cin >> n >> a >> b;
  vector<lint> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(RALL(v));
  double sum = 0.0;
  for (int i = 0; i < a; i++) {
    sum += v[i];
  }

  printf("%.10f\n", sum / a);
  lint num = v[a - 1];

  if (num != v[0]) {
    // 個数は a 個で固定
    lint all = 0;
    lint contain = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == num) {
        all++;
        if (i < a) contain++;
      }
    }
  
    cout << COM[all][contain] << endl;
  } else {
    lint all = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == num) all++;
    }
    lint ans = 0;
    for (int x = a; x <= min(all, b); x++) {
      ans += COM[all][x];
    }
    cout << ans << endl;
  }
  return 0;
}
