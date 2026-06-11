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
vector <int> adj[N];


void solve() 
{
    int n;
    cin>>n;

    rep(i, n-1)
    {
        int a, b;
        cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);
    }   

    int dist1[n+1], distn[n+1];

    rep(i, n+1) 
    {
        dist1[i] = INT_MAX;
        distn[i] = INT_MAX;
    }

    queue<int> q;
    q.push(1);

    dist1[1] = 0;

    while(q.size())
    {
        int p = q.front();
        q.pop();

        for(auto j:adj[p])
        {
            if(dist1[j] > dist1[p] + 1)
            {
                dist1[j] = dist1[p] + 1;
                q.push(j);
            } 
        }
    }

    // rep(i, n)
    // {
    //     cout<<dist1[i+1]<<" ";
    // }
    // cout<<endl;

    q.push(n);

    distn[n] = 0;

    while(q.size())
    {
        int p = q.front();
        q.pop();

        for(auto j:adj[p])
        {
            if(distn[j] > distn[p] + 1)
            {
                distn[j] = distn[p] + 1;
                q.push(j);
            } 
        }
    }

    // rep(i, n)
    // {
    //     cout<<distn[i+1]<<" ";
    // }
    // cout<<endl;

    int p = 0, r = 0;

    for(int i = 1; i <= n; i++)
    {
        if(dist1[i] <= distn[i]) p++;
        else r++;
    }

    if(p > r)
    {
        cout<<"Fennec"<<endl;
    }
    else
    {
        cout<<"Snuke"<<endl;
    }
    



     
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