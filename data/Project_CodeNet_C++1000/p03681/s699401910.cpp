#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

ll f(ll n) {
    ll res = 1;
    FORD(i, n, 1) {
        res = (res * i) % 1000000007;
    }
    return res;
}

int main() {
    ll n, m; cin >> n >> m;
    // 犬猫の差の絶対値が1を超えるとNG
    if (abs(n - m) > 1) {
        cout << 0 << endl;
    } else {
        if (n == m) {
            // 同数であれば C/D/C/D, D/C/D/C
            // 2 * Cの順列数 * Dの順列数
            cout << (2 * f(n) * f(m)) % 1000000007 << endl;
        } else if (n > m) {
            // C/D/C/D/C
            // Cの順列数 * Dの順列数
            cout << (f(n) * f(m)) % 1000000007 << endl;
        } else {
            // D/C/D/C/D
            // Cの順列数 * Dの順列数
            cout << (f(n) * f(m)) % 1000000007 << endl;
        }
    }
    return 0;
}