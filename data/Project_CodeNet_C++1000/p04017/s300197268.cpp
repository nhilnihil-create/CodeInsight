//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n; cin>>n;
    vector<ll> x(n+2,0);
    x[0]=-INF; x.back()=INF;
    rep(i,n) cin>>x[i+1];
    ll L; cin>>L;
    vector<vector<ll>> dl_l(20,vector<ll>(n,0));
    vector<vector<ll>> dl_r(20,vector<ll>(n,0));
    
    rep(i,n){
        ll l=i+1,r=n+1,c;
        while(l!=r){
            c=(l+r+1)/2;
            if(x[c]<=x[i+1]+L) l=c;
            else r=c-1;
        }
        
        dl_l[0][i]=l-1;
        l=0,r=i+1;
        while(l!=r){
            c=(l+r)/2;
            if(x[c]>=x[i+1]-L) r=c;
            else l=c+1;
        }
        dl_r[0][i]=l-1;
    }
    for(int i=1;i<20;i++)rep(j,n){
        dl_l[i][j]=dl_l[i-1][dl_l[i-1][j]];
        dl_r[i][j]=dl_r[i-1][dl_r[i-1][j]];
    }
    ll q; cin>>q;
    rep(i,q){
        ll a,b,cur,ans=0,c; cin>>a>>b;
        a--; b--;
        cur=a;
        if(a<b){
            while(cur<b){
                c=1;
                rep(i,20){
                    if(dl_l[i][cur]>=b){
                        if(i){
                            cur=dl_l[i-1][cur];
                            ans+=c/2;
                        }
                        else{
                            cur=dl_l[0][cur];
                            ans++;
                        }
                        break;
                    }
                    c*=2;
                }
            }
        }
        else{
            while(cur>b){
                c=1;
                rep(i,20){
                    if(dl_r[i][cur]<=b){
                        if(i){
                            cur=dl_r[i-1][cur];
                            ans+=c/2;
                        }
                        else{
                            cur=dl_r[0][cur];
                            ans++;
                        }
                        break;
                    }
                    c*=2;
                }
            }
        }
        cout<<ans<<endl;
    }
}