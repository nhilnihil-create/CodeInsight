#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
set<LP> G;
set<LP> s;
ll ans[10];
int main(){
    ll h,w,n; cin >> h >> w >> n;
    REP(i,n){
        ll a,b; cin >>a >> b; 
        G.insert(make_pair(a,b));
        REP(i,3){
            REP(j,3){
                ll x = a+i-1;
                ll y = b+j-1;
                if(x>1&& x < h && y > 1&& y < w){
                    s.insert(make_pair(x,y));
                }
            }
        }
    }
    auto it = s.begin();
    while(it!=s.end()){
        ll cx = it->first;
        ll cy = it->second;
        ll tmp = 0;
        REP(i,3){
            REP(j,3){
                ll x = cx +i -1;
                ll y = cy +j -1;
                LP p(x,y);
                auto f = G.find(p);
                if(f != G.end())  tmp++;
            }
        }
        ans[tmp]++;
        it++;
    }
    ll b = 0;
    FOR(i,1,10){
        b+=ans[i];
    }
    ans[0] = (h-2)*(w-2) - b;
    REP(i,10){
        cout << ans[i] << endl;
    }



}