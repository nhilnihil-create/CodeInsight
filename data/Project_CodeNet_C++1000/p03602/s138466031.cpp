#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//clock_t start=clock();clock_t end=clock();cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
typedef pair<double,double> pdd;
typedef vector<vector<ll>> mat;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll mod5=1000000009;
ll inf=1LL<<60;
double pi=3.141592653589793238462643383279L;
double eps=1e-14;
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
#define mrep(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
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
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
ll popcount(ll n){
    ll ret=0;
    ll u=n;
    while(u>0){
        ret+=u%2;
        u/=2;
        
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    ll a[n][n];
    ll sum=0;
    rep(i,0,n)rep(j,0,n){
        cin>>a[i][j];
        sum+=a[i][j];
    }
    sum/=2;
    //cout<<sum<<endl;
    bool used[n][n];
    memset(used,false,sizeof used);
    rep(i,0,n-2){
        rep(j,i+1,n-1){
            rep(k,j+1,n){
                vector<pll> v;
                v.push_back({a[i][j],0});
                v.push_back({a[j][k],1});
                v.push_back({a[k][i],2});
                sort(v.begin(),v.end());
                if(v[2].first>v[0].first+v[1].first){
                    cout<<-1<<endl;
                    return 0;
                }
                else if(v[2].first==v[0].first+v[1].first){
                    if(v[2].second==0){
                        if(used[i][j]==false)sum-=a[i][j];
                        used[i][j]=true;
                        used[j][i]=true;
                    }
                    if(v[2].second==1){
                        if(used[j][k]==false)sum-=a[j][k];
                        used[j][k]=true;
                        used[k][j]=true;
                    }
                    if(v[2].second==2){
                        if(used[k][i]==false)sum-=a[k][i];
                        used[i][k]=true;
                        used[k][i]=true;
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
}



