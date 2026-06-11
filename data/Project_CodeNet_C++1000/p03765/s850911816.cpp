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

string s,t;
ll n,m,i,query,x,y,u,v;
ll b1[N],b2[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>s>>t; n = s.size(); m = t.size(); s = " " + s; t = " " + t;
    for (i = 1;i <= n;i++){
        b1[i] = b1[i - 1];
        if (s[i] == 'B') b1[i]++;
        else b1[i] += 2;
    }
    for (i = 1;i <= m;i++){
        b2[i] = b2[i - 1];
        if (t[i] == 'B') b2[i]++;
        else b2[i] += 2;
    }
    cin>>query;
    while(query--){
        cin>>x>>y>>u>>v;
        ll p = b1[y] - b1[x - 1],q = b2[v] - b2[u - 1];
        if (p%3 == q%3) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

