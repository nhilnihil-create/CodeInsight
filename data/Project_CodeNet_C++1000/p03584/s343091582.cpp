#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    int N;
    ll K;cin>>N>>K;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    
    ll ans=0;
    int dig=-1;
    
    for(int i=30;i>=0;i--){
        ll sum=0;
        if(K&(1<<i)){
            if(dig==-1){
                for(int j=0;j<N;j++){
                    if(A[j]>=(1<<i)) continue;
                    if(!(A[j]&(1<<i))) sum+=B[j];
                }
                ans=max(ans,sum);
                dig=i;
            }else{
                for(int j=0;j<N;j++){
                    bool flag=true;
                    if(A[j]>=(1<<(dig+1))) flag=false;
                    for(int k=dig;k>=i+1;k--){
                        if(!(K&(1<<k))){
                            if(A[j]&(1<<k)) flag=false;
                        }
                    }
                    if(A[j]&(1<<i)) flag=false;
                    if(flag) sum+=B[j];
                }
                ans=max(ans,sum);
            }
        }
        //cout<<ans<<endl;
    }
    
    ll sum=0;
    
    for(int j=0;j<N;j++){
        bool flag=true;
        if(A[j]>K) flag=false;
        for(int k=dig;k>=0;k--){
            if(!(K&(1<<k))){
                if(A[j]&(1<<k)) flag=false;
            }
        }
        if(flag) sum+=B[j];
    }
    
    ans=max(ans,sum);
    
    cout<<ans<<endl;
    
}
