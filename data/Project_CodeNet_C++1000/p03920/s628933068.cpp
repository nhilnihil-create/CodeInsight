/// Containers Start
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
/// C Header Files
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <math.h>
#include <stdio.h>
/// Containers End

using namespace std;

/// Math Start
#define PI acos(-1.0)
#define Pi 3.141592653589793
#define EPS (1e-7)
#define INF (0x3f3f3f3f)
/// Math End

/// Extra Start
#define nn '\n'
#define pb push_back
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
#define sz(a) int((a).size())
#define space " "
#define All(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
/// Extra End

#define rep(i, n) for (int i = 0; i < n; i++)
#define Cini(a)                                                                \
    int a;                                                                     \
    cin >> a;
#define Cinii(a, b)                                                            \
    int a, b;                                                                  \
    cin >> a >> b;
#define Ciniii(a, b, c)                                                        \
    int a, b, c;                                                               \
    cin >> a >> b >> c;
#define Cins(s)                                                                \
    string s;                                                                  \
    cin >> s;
#define Cinss(s1, s2)                                                          \
    string s1, s2;                                                             \
    cin >> s1 >> s2;
#define Cinc(c)                                                                \
    char c;                                                                    \
    cin >> c;
/// Functions End


/// Debug Start
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl;
#define deb3(x, y, z)                                                          \
    cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": "   \
         << z << endl;
/// Debug End

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

/**>>>>>>>>>>>>>>>>>>> END <<<<<<<<<<<<<<<<<<**/

/// template


template<class T>
map<T, T> prime_factor(T n) {
    map<T, T> ret;
    for (T i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return move(ret);
};

signed main(void) {
    cin.sync_with_stdio(false);
    cin.tie(0);
    Cini(N);
    ll consecutiveSum = 0;
    int lastSumedNumber = 0;
    rep(i,N){
        consecutiveSum += (ll)(i+1);
        lastSumedNumber = i+1;
        if(consecutiveSum>=N)break;
    }
    ll dif = consecutiveSum - N;
    rep(i,lastSumedNumber){
        int targetNum = i+1;
        if(targetNum==dif)continue;
        cout << targetNum << nn;
    }
    return 0;
}