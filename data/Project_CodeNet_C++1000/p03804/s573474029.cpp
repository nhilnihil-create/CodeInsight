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
    vector<string> a;
    vector<string> b;
    int n, m; cin >> n >> m;
    REP(i, n) {
        string tmp; cin >> tmp;
        a.push_back(tmp);
    }
    REP(i, m) {
        string tmp; cin >> tmp;
        b.push_back(tmp);
    }
    int a_width = a[0].size();
    int b_width = b[0].size();
    FOR(i, 0, n - m) {
        FOR(j, 0, a_width - b_width) {
            bool f = true;
            FOR(di, 0, m-1) {
                FOR(dj, 0, b_width-1) {
                    if (a[i+di][j+dj] != b[di][dj]) {
                        f = false;
                    }
                }
            }
            if (f) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}