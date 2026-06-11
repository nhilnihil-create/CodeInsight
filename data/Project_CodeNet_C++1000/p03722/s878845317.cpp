#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll> > t;
    REP(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        t.emplace_back(a,b,-c);
    }
    vll d(n,LLINF);
    d[0] = 0;
    REP(i,n-1){
        REP(j,m){
            if(d[get<1>(t[j])]>d[get<0>(t[j])]+get<2>(t[j])){
                d[get<1>(t[j])]=d[get<0>(t[j])]+get<2>(t[j]);
            }
        }
    }
    vector<bool> updated(n,true);
    REP(i,n){
        REP(j,m){
            if(d[get<1>(t[j])]>d[get<0>(t[j])]+get<2>(t[j])){
                d[get<1>(t[j])]=d[get<0>(t[j])]+get<2>(t[j]);
                updated[get<1>(t[j])] = false;
            }
        }
    }
    if(updated[n-1]){
        ll ret = -d[n-1];
        cout << ret << endl;
    }else{
        puts("inf");
    }

    return 0;
}