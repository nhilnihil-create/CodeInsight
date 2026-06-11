#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int f(int x, int y) {
    if(x > 0 && x > y && -x <= y) return f(-x, y) + 1;
    if(x >= 0 && abs(x) < abs(y)) return f(x + abs(abs(x) - abs(y)), y) + abs(abs(x) - abs(y));
    if(x < 0 && x > y) return f(x - abs(abs(x) - abs(y)), y) + abs(abs(x) - abs(y)) + 2;
    if(x < 0 && -x <= y) return f(-x, y) + 1;
    if(abs(x) == abs(y)) return x != y;
    int ret = INF;
    if(x <= y) ret = y - x;
    if(x < y && -x > y) {
        ret = min(ret, abs(abs(x) - abs(y)) + 1);  
    }
    return ret;
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    cout << f(x, y) << endl;

    return 0;
}
