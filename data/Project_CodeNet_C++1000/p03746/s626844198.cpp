#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> t(n);
    rep(i,m){
        ll a,b;cin>>a>>b;a--;b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    vector<bool> used(n,false);
    queue<int> que;
    que.push(0);
    vector<ll> tr;
    while(que.size()){
        int x=que.front();que.pop();
        tr.push_back(x);
        used[x]=true;
        bool ok=true;
        rep(i,t[x].size()){
            int y=t[x][i];
            if(used[y])continue;
            ok=false;
            que.push(y);
            break;
        }
        if(ok)break;
    }
    reverse(tr.begin(),tr.end());
    que.push(0);
    used[0]=false;
    while(que.size()){
        int x=que.front();que.pop();
        if(x!=0)tr.push_back(x);
        used[x]=true;
        bool ok=true;
        rep(i,t[x].size()){
            int y=t[x][i];
            if(used[y])continue;
            ok=false;
            que.push(y);
            break;
        }
        if(ok)break;
    }
    reverse(tr.begin(),tr.end());
    //経路復元
    cout<<tr.size()<<endl;
    rep(i,tr.size()) cout<<tr[i]+1<<" ";
    cout<<endl;
}