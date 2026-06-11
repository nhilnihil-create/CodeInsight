#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2 vector<vec>
#define vecll2 vector<vecll>
#define vec3 vector<vec2d>
#define vecll3 vector<vecll2d>
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(vector<T> v){for(T e:v)cout<<e<<" ";cout<<endl;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
void print(vector<vec> v){for(auto e:v){for(auto ee:e)cout<<ee<<" ";cout<<endl;}}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}

const int N=1e5+10;
const ll INF=1e9+7;
ll a[N<<4];
int sum[11];
main(){
    
    int h,w,n;scanf("%d%d%d",&h,&w,&n);
    int x,y;
    int cnt=0;
    ll m=(ll)(h-2)*(w-2);
    rep(iii,n){
        scanf("%d%d",&x,&y);
        rep(i,3)if( x-i>=1 && x-i<=h-2 ){
            rep(j,3)if(y-j>=1 && y-j<=w-2){
            a[cnt++]=(1ll<<32)*(x-i)+(y-j);
            }
        }
    }
    sort(a,a+cnt);
    ll t=1;
    rep(i,cnt){
        if(a[i]==a[i+1])t++;
        else sum[t]++,t=1,m--;
    }
    printf("%lld %d %d %d %d %d %d %d %d %d",m,sum[1],sum[2],sum[3],sum[4],sum[5],sum[6],sum[7],sum[8],sum[9]);
}

