#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <cstdio>
#include    <vector>
#include    <bitset>
#include    <string>
#include    <cctype>
#include     <cmath>
#include     <deque>
#include     <stack>
#include     <queue>
#include       <map>
#include       <set>
#include       <ctime>
using namespace std;
#define scd(a) scanf("%d", &a)
#define scdd(a,b) scanf("%d%d", &a, &b)
#define scddd(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define X first
#define Y second
#define lowbit(x) ((x) & (-x))
#define IOS ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
const ll mod =  998244353, LINF = 0x3f3f3f3f3f3f3f3f;;
const double eps = 1e-10, Pi = 2*acos(0);
int n, m;
int dp[110][110];
int deal(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];
    for(int i = 1; 2*i <= x; i++) {
        if(!deal(x - 2*i, y + i)) return dp[x][y] = 1;
    }

    for(int i = 1; 2*i <= y; i++){
        if(!deal(x + i, y - 2*i)) return dp[x][y] = 1;
    }

    return dp[x][y] = 0;
}
void init(){
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
                int cur = deal(i, j);
            if(!cur) printf("%d %d %d\n", cur, i, j);
        }
    }
}
void solve(){
    ll x, y;
    scanf("%lld%lld", &x, &y);
    if(abs(x - y) <= 1) printf("Brown\n");
    else printf("Alice\n");
}
int main()
{
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("in.txt", "w", stdout);
    #endif
    int ce, c = 1, flag = 1;
//    IOS;
//    cin.tie(0);
//    cout.tie(0);
    solve();
    return 0;
}
