#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;

ll rui(ll a,ll b){
    if(b==1) return a%mod;
    else if(b==0) return 1;
    else if(b%2==0) return (rui(a,b/2)*rui(a,b/2))%mod;
    else return (rui(a,b-1)*a)%mod;
}

int main(){
    
    int N;cin>>N;
    vector<ll> A(N),B(N),d(N,0);
    bool check=true;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    ll now=0;
    for(int i=0;i<N;i++){
        if(A[i]>now){
            now=A[i];
            d[i]=A[i];
        }
    }
    now=0;
    for(int i=N-1;i>=0;i--){
        if(B[i]>now){
            now=B[i];
            if(d[i]!=0&&d[i]!=B[i]) check=false;
            d[i]=B[i];
        }
    }
    bool cor=true;
    ll co,co2;
    for(int i=0;i<N;i++){
        if(!cor){
            if(A[i]!=co&&A[i]>B[i]) check=false;
        }
        if(A[i]==B[i]){
            cor=false;
            co=A[i];
        }
    }
    cor=true;
    for(int i=N-1;i>=0;i--){
        if(!cor){
            if(B[i]!=co2&&A[i]<B[i]) check=false;
        }
        if(A[i]==B[i]){
            cor=false;
            co2=A[i];
        }
    }
    if(cor) check=false;
    if(check){
        ll ans=1,cnt=0,pre=0;
        for(int i=0;i<N;i++){
            if(d[i]==0) cnt++;
            else if(d[i]!=0){
                if(cnt!=0&&pre!=0){
                    ans*=rui(min(pre,d[i]),cnt);
                }
                ans=ans%mod;
                cnt=0;
                pre=d[i];
            }
        }
        cout<<ans<<endl;
    }
    else cout<<0<<endl;
    
}
