#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll x, y, ans;

    cin >> x >> y;

    ans = abs(abs(x)-abs(y));

    if(x>0 && y>0 && x>y) ans += 2;

    if(x<0 && y<0 && x>y) ans += 2;

    if(x*y<0) ans += 1;

    if(x>0&&y==0 || x==0&&y<0) ans += 1;

    cout << ans << endl;

    return 0;
}