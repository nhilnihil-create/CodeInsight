#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n,kd;
    cin>>n>>kd;
    int k[30],a[n][30];
    int b[n];
    rep(i,30){
        k[29-i]=(kd&1);
        kd/=2;
    }
    rep(i,n){
        int s;
        cin>>s>>b[i];
        rep(j,30){
            a[i][29-j]=(s&1);
            s/=2;
        }
    }
    ll ans=-1;
    rep(i,30){
        if(k[i]==0)continue;
        int s[30];
        rep(j,i){
            s[j]=k[j];
        }
        s[i]=0;
        for(int j=i+1;j<30;++j){
            s[j]=1;
        }
        ll mx=0;
        rep(j,n){
            bool flag=true;
            rep(l,30){
                if(s[l]==0&&a[j][l]==1){
                    flag=false;
                    break;
                }
            }
            if(flag)mx+=b[j];
        }
        ans=max(mx,ans);
    }
    ll mx=0;
    rep(j,n){
        bool flag=true;
        rep(l,30){
            if(k[l]==0&&a[j][l]==1){
                flag=false;
                break;
            }
        }
        if(flag)mx+=b[j];
    }
    ans=max(mx,ans);
    cout<<ans<<endl;
}
