#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, m, a[100100];

int main(){

    int k = 0;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", a + i);

    for (int i = 0; i < m; i++) k += a[i] % 2;

    if (k > 2) {
        printf("Impossible\n");
        return 0;
    }

    if (m == 1) {
        if (n == 1) cout << 1 << endl << 1 << endl << 1 << endl;
        else {
            cout << a[0] << endl << 2 << endl << n - 1 << " " << 1 << endl;
        }
        return 0;
    }

    int was = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] % 2) {
            if (was) {
                swap(a[i], a[m - 1]);
                break;
            }
            was = true;
            swap(a[0], a[i]);
        }
    }

    vector<int> b;

    b.pb(a[0] + 1);
    for (int i = 1; i < m - 1; i++) b.pb(a[i]);
    b.pb(a[m - 1] - 1);

    vector<int> c;
    for (int i = 0; i < b.size(); i++)
        if (b[i]) c.pb(b[i]);

    for (int i = 0; i < m; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    printf("%d\n", sz(c));
    for (int i = 0; i < sz(c); i++) {
        if (i) printf(" ");
        printf("%d", c[i]);
    }
    printf("\n");

    return 0;
}
