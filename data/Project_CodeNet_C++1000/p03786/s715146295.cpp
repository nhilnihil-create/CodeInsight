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

int main() {
    ll n; cin >> n;
    vector<ll> v(n, 0);
    REP(i, n) {
        cin >> v[i];
    }
    sort(ALL(v));
    ll sum = 0;
    // 1 3 4
    // iまでのsumよりも次のやつが2倍以上だったら、そのiはNG
    // 1 2 7 20 30 40
    // 1, 2はならない？
    // ならないな...
    ll ng = 0;
    ll tmp = 0;
    REP(i, n-1) {
        sum += v[i];
        tmp++;
        if (sum * 2 < v[i+1]) {
            ng += tmp;
            tmp = 0;
        }
    }
    cout << n - ng << endl;
    return 0;
}