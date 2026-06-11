#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 10000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int n,m;
vector<int> g[100100];
bool used[100100];
deque<int> ans;

void dfs1(int x){
    used[x]=true;
    ans.push_back(x);
    rep(i,g[x].size()){
        if(!used[g[x].at(i)]){
            dfs1(g[x].at(i));
            return;
        }
    }
}

void dfs2(int x){
    used[x]=true;
    ans.push_front(x);
    rep(i,g[x].size()){
        if(!used[g[x].at(i)]){
            dfs2(g[x].at(i));
            return;
        }
    }
}

void dfs(int x){
    ans.push_back(x);
    used[x]=true;
    dfs1(g[x].at(0));
    rep(i,g[x].size()){
        if(!used[g[x].at(i)]){
            dfs2(g[x].at(i));
            return;
        }
    }
}

signed main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    rep(i,m){
        int a,b; cin>>a>>b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);
    cout<<ans.size()<<endl;
    rep(i,ans.size()-1)cout<<ans.at(i)+1<<' ';
    cout<<ans.back()+1<<endl;
    
}