#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#define ALL(c) (c).begin(), (c).end()
#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

void solve(){
    int n,k,a,b;
    cin>>n>>k;
    vector<pii> v;
    v.reserve(n);
    REP(_,n){
        cin>>a>>b;
        v.pb({a,b});
    }
    ll ans = 0;
    for(auto const& p:v)
        if((p.st&k) == p.st)
            ans += p.nd;
    for(int bitno=29;bitno>=0;--bitno){
        int bit = (k>>bitno)&1;
        if(!bit) continue;
        int maskk = k>>(bitno+1);
        ll acc=0;
        for(auto const& p:v){
            int x=p.st;
            int pref = (x>>(bitno+1));
            if((pref&maskk)==pref && ((x>>bitno)&1)==0)
                acc += p.nd;
        }
        ans = max(ans, acc);
    }
    cout<<ans<<'\n';
}

int main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    solve();
    return 0;
}
