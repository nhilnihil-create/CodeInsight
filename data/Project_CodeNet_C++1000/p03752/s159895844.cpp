#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n),ins(n);
    rep(i,n){
        cin>>a[i];
        ins[i]=a[i];
    }

    ll ans=INF;
    rep(i,(1<<n)){
        ll visible=1;//見える建物の数
        rep(j,n){
            if(j==0) continue;
            if((i>>j)&1) visible++;
        }
        if(visible<k) continue;//k個以上じゃないとだめ

        ll sum=0;//見るのに必要な費用
        ll MAX=0;//j個目のビルの手前にある建物のうち、最大の高さ
        rep(j,n){
            if(j==0) continue;
            if((i>>j)&1){
                rep(k,j) MAX=max(MAX,a[k]);//手前の建物の中で最大の高さを探す
                if(MAX-a[j]+1ll>=0){//j番目の建物がMAXより小さいなら増築    
                    sum+=(MAX-a[j]+1ll);//増築費用
                    a[j]+=(MAX-a[j]+1ll);
                }
            }
        }

        rep(j,n) a[j]=ins[j];//aを元に戻す

        ans=min(ans,sum);
    }

    cout<<ans<<endl;
    return 0;
}