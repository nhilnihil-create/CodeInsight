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
    ll n, c, k; cin >> n >> c >> k;
    vector<ll> v;
    REP(i, n) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(ALL(v));

    ll res = 0;
    queue<ll> q;
    REP(i, n) {
        // 方針
        // 到着時刻の小さいものから順にqueueに突っ込んでいき、
        // (1) queueのサイズがcになるか
        // (2) 次の到着時刻がqueueの先頭+kよりも遅いか
        // を満たしたら出発させてqueueを空にしてresインクリメント
        if (q.empty()) {
            q.push(v[i]);
        } else {
            if ((q.size() == c) || (q.front() + k < v[i])) {
                q = queue<ll>();
                res++;
            }
            q.push(v[i]);
        }
    }
    if (!q.empty()) {
        res++;
    }
    cout << res << endl;
    return 0;
}