#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
using namespace std;
typedef long long ll;
const int N = 1 * 1e6 + 5;
const ll mod = 1e9 + 7;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
int v[1005];
ll POW(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = (ans % mod * a % mod) % mod;
        b >>= 1;
        a = (a % mod * a % mod) % mod;
    }
    return ans;
}
int main(){/*
    freopen("in","r",stdin);
    freopen("out","w",stdout);*/
    fast;
    vector<int> pr;
    for(int i = 2; i < 1005; i++)
        if(!v[i]){
            pr.pb(i);
            for(int j = i * i; j < 1005; j += i)
                v[j] = 1;
        }
    int n;
    cin >> n;
    ll ans = 1;
    vector<int> aux;
    fore(i,0,sz(pr)){    
        if(pr[i] <= n){
            int nn = n;
            ll exp = 0;
            ll fp = pr[i];
            while(nn / fp > 0){
                exp += nn / fp;
                fp *= pr[i];    
            }
            ans = (ans % mod * (exp + 1) % mod) % mod;
        }
        else
            break;
    }
    cout << ans << '\n';
    return 0;   
}