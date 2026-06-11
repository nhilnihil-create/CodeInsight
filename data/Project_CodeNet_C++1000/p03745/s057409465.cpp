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
    vector<ll> v;
    int tmp;

    bool asc = false;
    bool desc = false;
    ll prev = -1;
    ll res = 0;
    REP(i, n) {
        cin >> tmp;
        v.push_back(tmp);

        if (prev == -1) {
            res++;
        } else if (!asc && !desc) {
            if (tmp > prev) {
                asc = true;
            } else if (tmp < prev) {
                desc = true;
            }
        } else if (asc) {
            if (tmp < prev) {
                res++;
                asc = false;
            }
        } else if (desc) {
            if (tmp > prev) {
                res++;
                desc = false;
            }
        }
        prev = tmp;
    }
    cout << res << endl;
    return 0;
}