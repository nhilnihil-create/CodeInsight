#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>
#include <climits>
#include <iterator>
#include <iomanip>
#include <stack>
#include <bitset>
#include <functional>
using namespace std;
const constexpr int INF = 1e9;
//typedef std::pair<std::string,double> P;

typedef long long ll;
typedef vector<int> VI;

#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

//グラフの隣接リスト
VI g[200010];
//頂点の入次数を管理
int h[100010];
ll N;

int a[200010];
int b[200010];
int c[200010];
ll sum[200010];
signed main(void) {
    cin >> N;
    vector<int> ans;
    int maxn=1;
    while(maxn*(maxn+1)/2<N) maxn++;
    for(int i=1; i<=maxn; ++i){
        if(i!=(maxn+1)*maxn/2-N) printf("%d\n", i);
    }
	return 0;
}
