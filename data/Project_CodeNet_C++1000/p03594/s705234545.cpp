#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);
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
int main(){
    int h,w,d;cin>>h>>w>>d;
    int col[2000][2000];
    if(d%2==1){
        rep(i,0,2000){
            rep(j,0,2000){
                if(i%2!=j%2)continue;
                if(i%2==0)col[i][j]=1;
                else col[i][j]=2;
            }
        }
    }
    else{
        for(int i=0;i<2000;i+=2){
            for(int j=0;j<2000;j+=2){
                int f=i/d,g=j/d;
              f%=2;g%=2;
                if(f==0){
                    if(g==0)col[i][j]=1;
                    else col[i][j]=2;
                }
                else{
                    if(g==0)col[i][j]=4;
                    else col[i][j]=3;
                }
            }
        }
        for(int i=1;i<2000;i+=2){
            for(int j=1;j<2000;j+=2){
                col[i][j]=col[i-1][j-1];
            }
        }
    }
    char out[4]={'R','G','Y','B'};
    rep(i,0,h){
        rep(j,0,w){
            int s=i+j;
            int t=i-j+1000;
            cout<<out[col[s][t]-1];
        }
        cout<<endl;
    }
    
}

