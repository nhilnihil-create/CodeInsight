#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int ans, x, N, t;
map<int, int> c;

int main(void) {
    scanf("%d", &N);
    rep(i, 0, N) {
        int a;
        scanf("%d", &a);

        if (c[a] > 0) x++;
        else t++;

        c[a]++;
    }

    ans = t;
    if (x % 2 != 0) ans--;
    printf("%d\n", ans);

	return 0;
}
