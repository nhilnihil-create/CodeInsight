#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <bitset>

#define mst(a,b) memset(a,b,sizeof(a))
#define scd(x) scanf("%d", &x)
#define scdd(x,y) scanf("%d%d", &x, &y)
#define scddd(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double pi = 2*acos(0.0);
const double eps = 1e-6;
const ll mod = 998244353;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("ans.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scdd(n, m);
    printf("%s\n", abs(n-m) <= 1 ? "Brown": "Alice");
    return 0;
}
