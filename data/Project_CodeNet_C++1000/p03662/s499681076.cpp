#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1e18;

signed main(){
    int n;
    cin>>n;
    Graph G(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(n,-1),dist1(n,-1),pr(n);
    queue<int> que;
    dist[0]=0;
    que.push(0);
    while(!que.empty()){
        int v=que.front();que.pop();
        for(int nv:G[v]){
            if(dist[nv]!=-1) continue;
            dist[nv]=dist[v]+1;
            pr[nv]=v;
            que.push(nv);
        }
    }
    int d=dist[n-1]-1;
    int cnt;
    if(d%2==0) cnt=d/2+1;
    else cnt=(d+1)/2+1;
    vector<int> path;
    path.push_back(n-1);
    while(true){
        int m=path.size();
        int mm=pr[path[m-1]];
        path.push_back(mm);
        if(mm==0) break;
    }
    reverse(all(path));
    int m=path.size();
    if(d==0) dist1[n-1]=0;
    else{
        int u=1;
        int uu;
        while(true){
            if(u==cnt){
                uu=path[u];
                break;
            }
            u++;
        }
        dist1[uu]=0;
    }
    queue<int> q;
    dist1[0]=0;
    q.push(0);
    int cc=0;
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int nv:G[v]){
            if(dist1[nv]!=-1) continue;
            dist1[nv]=dist1[v]+1;
            q.push(nv);
            cc++;
        }
    }
    int c=n-2-cc;
    if(cc<=c) cout<<"Snuke"<<endl;
    else cout<<"Fennec"<<endl;
}