
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//#include <regex>

/* g++ -g -std=c++0x */
/* g++ -g -std=c++11 */

using namespace std;

// std::ios::sync_with_stdio(false);

// freopen("input.txt", "rt", stdin);
// freopen("output.txt", "wt", stdout);

#define ALL(c)          (c).begin(), (c).end()
#define ALLR(c)         (c).rbegin(), (c).rend()
#define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
#define FORR(i,a,b)     for (int i=(a); i > (b); --i)
#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                             i != (c).end(); ++i)
#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                             i != (c).rend(); ++i)
#define SZ(array)       (sizeof(array)/sizeof(array[0]))
#define lc(x)           (x<<1)     /* 2*x */
#define rc(x)           (x<<1 | 1) /* 2*x+1 */
#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */

typedef long long       LL;
typedef map<int,int>    MII;
typedef pair<int,int>   PII;
typedef set<int>        SI;
typedef vector<bool>    VB;
typedef vector<double>  VD;
typedef vector<int>     VI;
typedef vector<string>  VS;

/* check if a key is in container C */
template <class C>
inline bool in_(const typename C::key_type& k, const C& A)
{ return A.find(k) != A.end(); }
inline bool in_(const string& s, const string& S)
{ return S.find(s) != string::npos; }

/* grid 4-coloring, Chebyshev Distance */
/*
 * 曼哈顿距离是一个立着的正方形, 不方便处理.    d = |xi-xj|+|yi-yj|
 * 将矩阵旋转45°, 转为切比雪夫距离(正方形).     d = max{|xi-xj|,|yi-yj|}
 */

const int maxn = 510;
const char color[2][2] = { {'R','G'},{'B','Y'} };
char ans[maxn][maxn];
int H,W,d;

int main()
{
/* #ifndef ONLINE_JUDGE */
/*     freopen("foo", "rt", stdin); */
/* #endif */
    while (cin >> H >> W >> d) {
        int c1,c2; c1 = c2 = 0;
        for (int i = -maxn*2; i <= maxn*2; i += d) {
            for (int j = -maxn*2; j <= maxn*2; j += d) {
                FOR(x,0,d) FOR(y,0,d) {
                    const int c = color[c1][c2];
                    const int I = i+x;
                    const int J = j+y;
                    const int ii = (I+J)/2;
                    const int jj = (I-J)/2;
                    if (0 <= ii && ii < H && 0 <= jj && jj < W)
                        ans[ii][jj] = c;
                }
                c2 ^= 1;
            }
            c1 ^= 1;
        }
        FOR(i,0,H) {
            FOR(j,0,W)
                cout << ans[i][j];
            cout << endl;
        }
    }
    return 0;
}
