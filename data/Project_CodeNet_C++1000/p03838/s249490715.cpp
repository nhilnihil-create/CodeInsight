//
//AtCoder Grand Contest 008
//A
//https://atcoder.jp/contests/agc008/tasks/agc008_a
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <functional>
#include <cassert>
#include <bitset>

using namespace std;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SIZE(x) (int)(x).size()
#define SIZEL(x) (ll)(x).size()
#define MSG(a) cout << #a << " " << a << endl;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

const double PI = 3.14159265358979323846;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    int x, y;
    cin >> x >> y;

    int ans=0;
    if (abs(x)==abs(y)){
        if (x==y) ans=0;
        else ans=1;
    }else if (abs(x)<abs(y)){
        if (x<0) ans++;
        if (y<0) ans++;
        ans = ans + abs(y) - abs(x);
    }else{
        if (x>0) ans++;
        if (y>0) ans++;
        ans = ans + abs(x) - abs(y);
    }
    cout << ans << endl;
    return 0;
}
