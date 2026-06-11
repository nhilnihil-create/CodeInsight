#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1LL<<60;
const int INF = 1LL<<17;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string YES[2] = {"NO", "YES"};
string yes[2] = {"No", "Yes"};



int main(){
    ll n;   cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i, n){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(ALL(a));
    set<ll> st;
    st.insert(0);st.insert(n+1);
    ll res=0;
    rep(i, n){
        ll index=a[i].second;
        auto itr = st.lower_bound(index);
        ll right = *itr;
        ll left = *prev(itr);
        st.insert(index);
        //cout << a[i].second-left << ' ' << right-a[i].second << endl;
        res += a[i].first*(left-a[i].second)*(a[i].second-right);
    }
    cout << res << endl;
}
