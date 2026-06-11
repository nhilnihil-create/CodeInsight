#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}

int main(){
    int N; cin >> N;
    ll L; cin >> L;
    vector<ll> v(N);
    ll tmp;
    REP(i,N) cin >> v[i];
    bool f = false;
    REP(i,N-1){
        if(v[i]+v[i+1]>=L) {
            f=true;
            tmp=i+1;
            break;
        }
    }
    if(!f) cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        deque<ll> res;
        FOR(i,1,N) {
            if(i<tmp) res.push_back(i);
            if(i>tmp) res.push_front(i);
        }
        res.push_back(tmp);
        while(!res.empty()) {
            cout << res.front() << endl;
            res.pop_front();
        }
    }
    return 0;
}