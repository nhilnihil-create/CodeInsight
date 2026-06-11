#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;

const ll N = 1e5 + 9;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> LL;
set<ll> s;
ll n,a[N],i,ans[N];
unordered_map<ll,LL> mp;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    s.insert(0);
    cin>>n;
    for (i = 1;i <= n;i++){
        cin>>a[i]; s.insert(a[i]);
    }
    for (i = n;i > 0;i--){
        mp[a[i]].fs = i;
        mp[a[i]].sc++;
    }
    mp[0].fs = mp[0].sc = 0;
    while(s.size() > 1){
        //cout<<1;
        ll t = *prev(s.end()); s.erase(t);
        ll p = *prev(s.end()),q = t - p;
        ll pos = mp[t].fs;
        //cout<<t<<" "<<pos<<"\n";
        ans[pos] += q*(mp[t].sc);
        mp[p].fs = min(mp[t].fs,mp[p].fs); mp[p].sc += mp[t].sc;
    }
    for (i = 1;i <= n;i++) cout<<ans[i]<<"\n";
}

