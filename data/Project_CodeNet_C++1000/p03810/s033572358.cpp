#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

int gcd(int a, int b) {
    while (b) { int t = a%b; a = b; b = t; }
    return a;
}

const int MAXN = 100005;
int a[MAXN];

int n;

bool solve() {
    int even = 0;
    FOR1(i, n) even += (a[i] % 2 == 0);

    if (even % 2 == 1) {
        return true;
    }
    else if (even < n - 1) {
        return false;
    }
    else {
        FOR1(i, n) {
            if (a[i] % 2) {
                if (a[i] == 1) {
                    return false;
                }
                else {
                    a[i]--;
                }
            }
        }

        int g = a[1];
        for (int i = 2; i <= n; i++) g = gcd(g, a[i]);
        FOR1(i, n) a[i] /= g;

        return !solve();
    }
}

int main() {
    GI(n);
    FOR1(i, n) GI(a[i]);

    if (solve()) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }

    return 0;
}