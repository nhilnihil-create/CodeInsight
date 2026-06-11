#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
vector<int> v[100010];
vector<int> ans;
bool used[100010];
int c=0;
void dfs(){
    int now=ans.back();
    //cout<<now<<" "<<c<<endl;
    rep(i,0,v[now].size()){
        int ne=v[now][i];
        if(used[ne])continue;
        used[ne]=true;
        ans.push_back(ne);
        dfs();
        break;
    }
    if(c==0){
        reverse(ans.begin(),ans.end());
        c=1;
        now=ans.back();
        rep(i,0,v[now].size()){
            int ne=v[now][i];
            if(used[ne])continue;
            used[ne]=true;
            ans.push_back(ne);
            dfs();
            break;
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    
    rep(i,0,m){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        
    }
    ans.push_back(1);
    
    fill(used,used+n+1,false);
    used[1]=true;
    dfs();
    cout<<ans.size()<<endl;
    rep(i,0,ans.size()-1)cout<<ans[i]<<" ";
    cout<<ans.back()<<endl;
}
