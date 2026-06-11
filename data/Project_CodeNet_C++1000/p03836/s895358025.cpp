#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <list>
#include <deque>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll MOD = 1000000007;
ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}

int main()
{
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int migi = tx - sx;
    int upper = ty - sy;
    for(int i = 0; i < migi; i++) cout <<'R';
    for(int i = 0; i < upper; i++) cout << 'U';
    for(int i = 0; i < migi; i++) cout << 'L';
    for(int i = 0; i < upper; i++) cout << 'D';
    cout << 'D';
    for(int i = 0; i < migi + 1; i++) cout <<'R';
    for(int i = 0; i < upper + 1; i++) cout << 'U';
    cout <<'L';
    cout <<'U';
    for(int i = 0; i < migi + 1; i++) cout <<'L';
    for(int i = 0; i < upper + 1; i++) cout << 'D';
    cout <<'R';
    cout << endl;
}
