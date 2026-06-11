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
    int n, m; cin >> n >> m;
    int a[200001]; INITA(a, 0, 200000, 0);
    int b[200001]; INITA(b, 0, 200000, 0);
    set<int> st;
    REP(i, m) {
        cin >> a[i] >> b[i];
        if (a[i] == 1) {
            st.insert(b[i]);
        }
        if (b[i] == 1) {
            st.insert(a[i]);
        }
    }
    REP(i, m) {
        if ((st.find(a[i]) != st.end()) && (b[i] == n)) {
            cout << "POSSIBLE" << endl;
            return 0;
        } else if ((st.find(b[i]) != st.end()) && (a[i] == n)) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}