#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> v[n+1];
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(k%2==0){
        int d[n+1][n];
        rep(i,0,n+1)fill(d[i],d[i]+n,0);
        rep(i,1,n+1){
            bool used[n+1];
            fill(used,used+n+1,false);
            int dis[n+1];
            dis[i]=0;
            queue<int> q;
            q.push(i);
            used[i]=true;
            while(q.size()>0){
                int now=q.front();q.pop();
                d[i][dis[now]]++;
                rep(j,0,v[now].size()){
                    int ne=v[now][j];
                    if(used[ne])continue;
                    used[ne]=true;
                    q.push(ne);
                    dis[ne]=dis[now]+1;
                }
            }
        }
        int ans=0;
        rep(i,1,n+1){
            int sum=0;
            rep(j,0,k/2+1){
                sum+=d[i][j];
            }
            ans=max(ans,sum);
        }
        cout<<n-ans<<endl;
    }
    else{
        int par[n+1];
        par[1]=0;
        queue<int> qq;
        qq.push(1);
        while(qq.size()){
            int now=qq.front();qq.pop();
            rep(i,0,v[now].size()){
                int ne=v[now][i];
                if(ne==par[now])continue;
                par[ne]=now;
                qq.push(ne);
                
            }
        }
        int d[n+1][n];
        rep(i,0,n+1)fill(d[i],d[i]+n,0);
        rep(i,2,n+1){
            bool used[n+1];
            fill(used,used+n+1,false);
            int dis[n+1];
            dis[i]=0;
            dis[par[i]]=0;
            queue<int> q;
            q.push(i);
            q.push(par[i]);
            used[i]=true;
            used[par[i]]=true;
            while(q.size()>0){
                int now=q.front();q.pop();
                d[i][dis[now]]++;
                rep(j,0,v[now].size()){
                    int ne=v[now][j];
                    if(used[ne])continue;
                    used[ne]=true;
                    q.push(ne);
                    dis[ne]=dis[now]+1;
                }
            }
        }
        int ans=0;
        rep(i,2,n+1){
            int sum=0;
            rep(j,0,k/2+1){
                sum+=d[i][j];
            }
            ans=max(ans,sum);
        }
        cout<<n-ans<<endl;
    }
}
