#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll INF = (ll)1e18;
const int N = 300300;
ll a[N];
int n;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    ll ans = INF;
    for (int i = 0; i < n - 1; i++) {
        sum -= 2 * a[i];
        ans = min(ans, abs(sum));
    }
    printf("%lld\n", ans);

    return 0;
}