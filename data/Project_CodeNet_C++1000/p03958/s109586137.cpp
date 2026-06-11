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
    ll k, t; cin >> k >> t;
    vector<ll> a;
    ll tmp;
    ll arr[10001]; INITA(arr, 0, 10000, 0);
    REP(i, t) {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(ALL(a), greater<ll>());

    // まず最多ケーキ (a[0]個) を配置して、その間に入れていく
    // 最多を配置した時点だと a[0]-1 ペアあり、他のを間に入れるごとに1削れる
    cout << max((ll) a[0]-1-(k-a[0]), (ll) 0) << endl;
    return 0;
}