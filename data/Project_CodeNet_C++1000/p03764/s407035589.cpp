#include "bits/stdc++.h"
#include <chrono>
#include <tuple>
#include <string>
#include <random>
#include <cstdio>
#define ll long long int
// #define endl '\n'
#define pb push_back
#define mp make_pair
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
ll max(ll a, ll b){ if(a>b)return a;return b;}
ll min(ll a, ll b){ if(a < b) return a;return b;}
const int N = 100001;
vector<pair<ll, ll> > adj[N];
ll mod = 1000000007;

void solve() 
{
    int n, m;
    cin>>n>>m;

    vi x(n), y(m);

    rep(i, n) cin>>x[i];

    rep(i, m) cin>>y[i];

    sort(all(x)), sort(all(y));

    ll a = 0, b = 0;

    rep(i, n)
    {
        a += (i*x[i] - (n - i - 1)*x[i]);
        a += mod;
        a = a%mod;
    }

    // cout<<a<<endl;

    rep(i, m)
    {
        b += (i*y[i] - (m - i - 1)*y[i]);
        b+=mod;
        b = b%mod;
    }

    ll ans = (a*b)%mod;
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
