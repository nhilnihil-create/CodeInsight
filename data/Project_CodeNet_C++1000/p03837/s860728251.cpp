#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define SET(A,VAL) memset(A, VAL, sizeof(A))
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
const int MAX = 1e6+8;
const int sz = 1e5+5;
void f_io(){
    IOS;
}
int dist[105][105];
int32_t main(){
    f_io();
    int t = 1;
    //cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        std::vector<pii> edges(m);
        vi weight(m);
        rep(i,0,m){
            int a,b; cin>>a>>b>>weight[i];
            edges[i] = {--a,--b};          
        }
        //for(auto k : edges) trace2(k.ff,k.ss);
        rep(a,0,n)rep(b,0,n){
            if(a == b) dist[a][b] = 0;
            else dist[a][b] = INT_MAX;
        }
        rep(i,0,m){
            dist[edges[i].ff][edges[i].ss] = min(dist[edges[i].ff][edges[i].ss],weight[i]);
            dist[edges[i].ss][edges[i].ff] = min(dist[edges[i].ff][edges[i].ss],weight[i]);
        }
        rep(k,0,n)rep(i,0,n)rep(j,0,n){
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
        int ans = m;
        rep(i,0,m){
            bool flag = false;
            rep(j,0,n) if(dist[j][edges[i].ff] + weight[i] == dist[j][edges[i].ss]) flag = 1;
            if(flag) ans--;
        }
        cout<<ans<<endl;

    }
}