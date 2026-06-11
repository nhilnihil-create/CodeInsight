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
    string s; cin >> s;
    map<char, int> m;
    set<char> st;
    int res = 100000;
    for (char tc: s) {
        if (st.find(tc) != st.end()) {
            continue;
        }
        st.insert(tc);

        int tmp = 0;
        int mx = 0;
        for (char c: s) {
            if (c != tc) {
                tmp++;
            } else {
                mx = max(tmp, mx);
                tmp = 0;
            }
        }
        mx = max(tmp, mx);
        res = min(res, mx);
    }
    cout << res << endl;
    return 0;
}