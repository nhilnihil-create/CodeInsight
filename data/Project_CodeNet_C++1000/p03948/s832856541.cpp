#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b)  for(ll (i)=a;(i)<(b);++(i))
#define RFOR(i,a,b) for(ll (i)=a;(i)>=(b);--(i))
#define REP(i,n)    FOR(i,0,n)
#define RREP(i,n)   RFOR(i,n,0)
#define SZ(v)       (ll)(v).size()
#define ALL(v)      (v).begin(),(v).end()
#define UNIQ(v)     sort(ALL(v));(v).erase(unique(ALL(v)),(v).end())
#define IN(x,l,r)   ((l)<=(x)&&(x)<=(r))
#define BIT(n)      (1LL<<(n))
#define PQ(T)       priority_queue<T,vector<T>,greater<T>>
#define SHOW(x)     cout<<#x<<" = "<<x<<endl

template<typename T>string join(const vector<T>& v, string d=" ")
{stringstream s;REP(i,SZ(v))s<<d<<v[i];return s.str().substr(d.length());}

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v)
{if(SZ(v))s<<join(v,", ");return s;}

const ll inf = 1e15;
const ll mod = 1e9+7;
const double eps = 1e-10;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    ll N, T; cin >> N >> T;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    
    ll minv = inf;
    ll maxv = 0;
    ll ans = 0;
    REP(i, N) {
        if (minv > A[i]) {
            minv = A[i];
        } else if (maxv < A[i] - minv) {
            maxv = A[i] - minv;
            ans = 1;
        } else if (maxv == A[i] - minv) {
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
