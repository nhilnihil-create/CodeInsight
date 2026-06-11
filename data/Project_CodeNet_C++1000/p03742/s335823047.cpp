#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define lb(x) (x&-x)
#define X first
#define Y second
#define ls rt<<1
#define rs rt<<1|1
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1e5+10;
const int maxm = 1e6;
const int mod = 1e9+7;

int a[maxn],b[maxn];
int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    if(n<m) swap(n,m);
    if(n-m<2) puts("Brown");
    else puts("Alice");
    return 0;
}
