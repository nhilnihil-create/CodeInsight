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
    int a[n+1];
    vector<int> v[n+1],w[n+1];
    rep(i,1,n+1){
        cin>>a[i];
        
        if(i>1){
            v[i].push_back(a[i]);
            w[a[i]].push_back(i);
        
        }
    }
    int ans=0;
    if(a[1]!=1){
        a[1]=1;
        ans++;
    }
    queue<int> q;
    int d[n+1];
    int cnt[n+1];
    fill(cnt,cnt+n+1,0);
    fill(d,d+n+1,-1);
    rep(i,1,n+1){
        if(w[i].size()==0){
            q.push(i);
            d[i]=0;
        }
    }
    while(q.size()>0){
        int now=q.front();q.pop();
        if(now==1)continue;
        if(d[now]==k-1){
            if(a[now]!=1){
                ans++;
                d[a[now]]=max(d[a[now]],0);
                cnt[a[now]]++;
                if(cnt[a[now]]==w[a[now]].size()){
                    q.push(a[now]);
                }
            }
        }
        else{
            d[a[now]]=max(d[a[now]],d[now]+1);
            cnt[a[now]]++;
            if(cnt[a[now]]==w[a[now]].size())q.push(a[now]);
        }
    }
    cout<<ans<<endl;
    //rep(i,1,n+1)cout<<d[i]<<endl;
}
