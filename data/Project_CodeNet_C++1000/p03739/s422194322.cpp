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


int main() {
    ll n,ans=INF,ans_=0; cin>>n;
    vector<ll> sum(n,0);
    ll cnt=0;
    rep(i,n){
        cin>>sum[i];
        sum[i]+=cnt; cnt=sum[i];
    }
    ll a=1,d=0;
    rep(i,n){
        if(a*(sum[i]+d)<=0){
            ans_+=abs(a-(sum[i]+d));
            d+=a-(sum[i]+d); 
        }
        a*=(-1);
    }
    ans=min(ans,ans_);
    a=-1; d=0; ans_=0;
    rep(i,n){
        if(a*(sum[i]+d)<=0){
            ans_+=abs(a-(sum[i]+d));
            d+=a-(sum[i]+d); 
        }
        a*=(-1);
    }
    cout<<min(ans,ans_)<<endl;
}