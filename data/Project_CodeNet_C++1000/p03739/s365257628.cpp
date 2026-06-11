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
    ll n,ans=INF,cnt,sum; cin>>n;
    vector<ll> a(n,0);
    rep(i,n) cin>>a[i];
    sum=0; cnt=0;
    rep(i,n){
        sum+=a[i];
        if(i%2){
            if(sum>=0){
                cnt+=sum+1;
                sum=-1;
            }
        }
        else{
            if(sum<=0){
                cnt+=1-sum;
                sum=1;
            }
        }
    }
    ans=min(ans,cnt);
    sum=0; cnt=0;
    rep(i,n){
        sum+=a[i];
        if(i%2==0){
            if(sum>=0){
                cnt+=sum+1;
                sum=-1;
            }
        }
        else{
            if(sum<=0){
                cnt+=1-sum;
                sum=1;
            }
        }
    }
    ans=min(ans,cnt);
    cout<<ans<<endl;
}