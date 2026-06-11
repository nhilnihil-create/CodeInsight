#include "bits/stdc++.h"
#include <chrono>
#include <random>
#include <cstdio>
#define ll long long int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mod 1000000007LL
#define rep(i,n) for(ll i=0;i<n;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define pll pair<ll, ll>
#define pint pair<int, int>
#define S second
#define F first
#define all(c) (c).begin(),(c).end()
using namespace std;
// ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// ll modInverse(ll a){return power(a,mod-2);}
const int N=500001;
// vector<pair<ll, ll> > adj[N];
// bool vis[N];
ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); } 
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
#define pi 3.14159265358979323846264338
using namespace std; 
ll max(ll a, ll b){ if(a>b)return a;return b;}
ll min(ll a, ll b){ if(a < b) return a;return b;}
ll inf = 100000000000000000;
vector <pint> adj[N];

ll n, a, b;
vl h(N);

bool check(ll x)
{
    ll tot = 0;

    rep(i, n)
    {

        if(h[i] > b*x)
        {
            tot += ((h[i] - b*x)/(a-b));
            if((h[i] - b*x) % (a - b) != 0) tot++;
        }

        else continue;
    }

    if(tot > x) return false;
    return true;
}

void solve() 
{
    
    cin>>n>>a>>b;
    
    rep(i, n) cin>>h[i];

    ll l = 0, r = 1e10;
    ll ans = LLONG_MAX;

    while(l <= r)
    {
        ll mid = (l+r)/2;
        // cout<<l<<" "<<r<<endl;
        if(check(mid))
        {
            r = mid - 1;           
            ans = min(ans, mid);
        }
        else
        {
            l = mid + 1;
        }
    }

    if(check(l))
    {
        ans = min(ans, l);
    }

    // cout<<check(31250000000000000)<<endl;

    // cout<<check(3)<<endl;

    cout<<ans<<endl;

}

int main()
{

    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin>>T;
    int t=0;
    while(t++<T)

    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        // cout<<'\n';
    }


    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}