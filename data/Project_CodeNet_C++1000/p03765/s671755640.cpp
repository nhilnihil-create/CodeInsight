/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

char s[maxn], t[maxn];
ll prefix_s[maxn], prefix_t[maxn];

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'B') prefix_s[i] = prefix_s[i - 1] + 1LL;
        else prefix_s[i] = prefix_s[i - 1] + 2LL;
    }
    for (int i = 1; i <= m; i++) {
        if (t[i] == 'B') prefix_t[i] = prefix_t[i - 1] + 1LL;
        else prefix_t[i] = prefix_t[i - 1] + 2LL;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ll A = prefix_s[b] - prefix_s[a - 1];
        ll B = prefix_t[d] - prefix_t[c - 1];
        if ((A - B) % 3LL == 0) puts("YES");
        else puts("NO");
    }

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
