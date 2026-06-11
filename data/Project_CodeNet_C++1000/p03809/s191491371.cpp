#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
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
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    ll a[n+1];
    rep(i,1,n+1)cin>>a[i];
    vector<ll> v[n+1];
    rep(i,0,n-1){
        int c,d;cin>>c>>d;
        v[c].push_back(d);
        v[d].push_back(c);
        
    }
    v[1].push_back(0);
    ll par[n+1];
    par[1]=0;
    queue<ll> q;
    q.push(1);
    bool used[n+1];
    fill(used,used+n+1,false);
    used[0]=true;
    used[1]=true;
    while(q.size()>0){
        ll now=q.front();q.pop();
        rep(i,0,v[now].size()){
            ll ne=v[now][i];
            if(used[ne])continue;
            used[ne]=true;
            par[ne]=now;
            q.push(ne);
        }
    }
   // cout<<par[1]<<endl;
    ll cnt[n+1];
    fill(cnt,cnt+n+1,0);
    ll su=0;
    rep(i,2,n+1){
        if(v[i].size()==1){
            q.push(i);
            su+=a[i];
        }
    }
    if(v[1].size()==2)su+=a[1];
    if(su%2==1){
        cout<<"NO"<<endl;
        return 0;
    }
    ll f[n+1];
    fill(f,f+n+1,0);
    //cout<<v[1].size()<<endl;
    while(q.size()>0){
        ll now=q.front();
        q.pop();
        //cout<<now<<endl;
        //rep(i,1,6)cout<<f[i]<<" ";
        //cout<<endl;
        if(v[now].size()==1)f[now]=a[now];
        else{
            ll sum=0;
            rep(i,0,v[now].size()){
                if(v[now][i]==par[now])continue;
                sum+=f[v[now][i]];
                if(f[v[now][i]]>a[now]){
                    cout<<"NO"<<endl;
                    return 0;
                }
              //  if(now==1)cout<<v[now][i]<<" ";
            }
            //cout<<sum<<" "<<a[now]<<" "<<now<<endl;
            if(sum<a[now]){
                cout<<"NO"<<endl;
                return 0;
            }
            ll u=a[now]*2;
            if(v[now].size()==2){
                //cout<<a[now]<<" "<<sum<<endl;
                if(a[now]!=sum){
                    cout<<"NO"<<endl;
                    return 0;
                }
                f[now]=sum;
            }
            else{
                if(u<sum){
                    cout<<"NO"<<endl;
                    return 0;
                }
                f[now]=u-sum;
            }
            
        }
        //cout<<f[1]<<endl;
        if(now==1){
            if(v[now].size()==2){
                f[now]=0;
            }
            if(f[now]==0){
                cout<<"YES"<<endl;
                
            }
            else cout<<"NO"<<endl;
            return 0;
        }
        cnt[par[now]]++;
        if(cnt[par[now]]==v[par[now]].size()-1)q.push(par[now]);
    }
    
}
